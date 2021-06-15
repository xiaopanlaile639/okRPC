

#include <functional>

#include <google/protobuf/descriptor.h>

#include <muduo/net/TcpConnection.h>
#include <muduo/base/Logging.h>
#include <muduo/net/Buffer.h>

#include "rpc.pb.h"
#include "RpcChannel.h"
#include "service.h"

using namespace muduo;
using namespace muduo::net;
using namespace okrpc;



//Q:为什么需要定义在这？
namespace okrpc
{
const char rpctag [] = "RPC0";
}

//////////////////utilities///////////////////////////
// template<typename T>
// inline T* get_pointer(const std::shared_ptr<T>& ptr)
// {
//   return ptr.get();
// }

// template<typename T>
// inline T* get_pointer(const std::unique_ptr<T>& ptr)
// {
//   return ptr.get();
// }


//////////////////////////////////////////////////


static int test_down_pointer_cast()
{
  //Q:为什么外部已经引用了okrpc，这里RpcMessage还需要加上域作用符号

  ::std::shared_ptr<::google::protobuf::Message> msg(new okrpc::RpcMessage);
  ::std::shared_ptr<okrpc::RpcMessage> rpc(::google::protobuf::down_pointer_cast<okrpc::RpcMessage>(msg));
  assert(msg && rpc);
  if (!rpc)
  {
    abort();
  }
  return 0;
}

static int dummy __attribute__((unused)) = test_down_pointer_cast();

RpcChannel::RpcChannel()
    : codec_(std::bind(&RpcChannel::onRpcMessage, this, _1, _2, _3)),
      services_(NULL)
{
  LOG_INFO << "RpcChannel::ctor - " << this;
}

RpcChannel::RpcChannel(const TcpConnectionPtr &conn)
    : codec_(std::bind(&RpcChannel::onRpcMessage, this, _1, _2, _3)),
      conn_(conn),
      services_(NULL)
{
  LOG_INFO << "RpcChannel::ctor - " << this;
}

RpcChannel::~RpcChannel()
{
  LOG_INFO << "RpcChannel::dtor - " << this;
}



void RpcChannel::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                            google::protobuf::RpcController* controller,
                            const ::google::protobuf::Message* request,
                            ::google::protobuf::Message* response,
                            ::google::protobuf::Closure* done)
{
  RpcMessage message;
  message.set_type(REQUEST);
  int64_t id = id_.incrementAndGet();
  message.set_id(id);
  message.set_service(method->service()->full_name());
  message.set_method(method->name());
  message.set_request(request->SerializeAsString()); // FIXME: error check

  OutstandingCall out = { response, done };
  {
  MutexLockGuard lock(mutex_);
  outstandings_[id] = out;
  }
  codec_.send(conn_, message);
}


// // Call the given method of the remote service.  The signature of this
// // procedure looks the same as Service::CallMethod(), but the requirements
// // are less strict in one important way:  the request and response objects
// // need not be of any specific class as long as their descriptors are
// // method->input_type() and method->output_type().
// void RpcChannel::CallMethod(const ::google::protobuf::MethodDescriptor *method,
//                             const ::google::protobuf::Message &request,
//                             const ::google::protobuf::Message *response,
//                             const ClientDoneCallback &done)
// {
//   // FIXME: can we move serialization to IO thread?
//   okrpc::RpcMessage message;
//   message.set_type(REQUEST);
//   int64_t id = id_.incrementAndGet();
//   message.set_id(id);
//   message.set_service(method->service()->full_name());
//   message.set_method(method->name());
//   message.set_request(request.SerializeAsString()); // FIXME: error check

//   OutstandingCall out = {response, done};
//   {
//     MutexLockGuard lock(mutex_);
//     outstandings_[id] = out;
//   }
//   codec_.send(conn_, message);
// }

void RpcChannel::onDisconnect()
{
  //FIXME:
}

void RpcChannel::onMessage(const TcpConnectionPtr &conn,
                           Buffer *buf,
                           Timestamp receiveTime)
{
  LOG_TRACE << "RpcChannel::onMessage " << buf->readableBytes();
  codec_.onMessage(conn, buf, receiveTime);
}

void RpcChannel::onRpcMessage(const TcpConnectionPtr &conn,
                              const RpcMessagePtr &messagePtr,
                              Timestamp receiveTime)
{
  assert(conn == conn_);
  //printf("%s\n", message.DebugString().c_str());
  RpcMessage &message = *messagePtr;

  LOG_TRACE << "RpcChannel::onRpcMessage " << message.DebugString();
  
  if (message.type() == RESPONSE)       //回复消息
  {
    int64_t id = message.id();
    //assert(message.has_response());
    assert(!message.response().empty()); //断言不为空

    OutstandingCall out = {NULL, NULL};
    bool found = false;

    {
      MutexLockGuard lock(mutex_);
      std::map<int64_t, OutstandingCall>::iterator it = outstandings_.find(id);
      if (it != outstandings_.end())
      {
        out = it->second;
        outstandings_.erase(it);
        found = true;
      }
      else
      {
#ifndef NDEBUG
        LOG_WARN << "Size " << outstandings_.size();
        for (it = outstandings_.begin(); it != outstandings_.end(); ++it)
        {
          LOG_WARN << "id " << it->first;
        }
#endif
      }
    }

    if (!found)
    {
      LOG_ERROR << "Unknown RESPONSE";
    }

    if (out.response)
    {
      // FIXME: can we move deserialization to other thread?
      ::google::protobuf::MessagePtr response(out.response->New());
      response->ParseFromString(message.response());
      if (out.done)
      {
        out.done->Run();  //(response);
      }
    }
    else
    {
      LOG_ERROR << "No Response prototype";
    }
  }
  else if (message.type() == REQUEST)   //请求消息
  {
    callServiceMethod(message);
  }
  else if (message.type() == ERROR)
  {
    // FIXME:
  }
}


//rpcMessage中调用此方法，来调用最终的服务函数
void RpcChannel::callServiceMethod(const RpcMessage &message)
{
  if (services_)
  {
    ServiceMap::const_iterator it = services_->find(message.service());
    if (it != services_->end())
    {
      Service *service = it->second;
      assert(service != NULL);
      const google::protobuf::ServiceDescriptor *desc = service->GetDescriptor();
      const google::protobuf::MethodDescriptor *method = desc->FindMethodByName(message.method());
      
      if (method)
      {
        // FIXME: can we move deserialization to other thread?
        //const
        //::google::protobuf::MessagePtr request(service->GetRequestPrototype(method).New());
         std::unique_ptr<google::protobuf::Message> request(service->GetRequestPrototype(method).New());

        request->ParseFromString(message.request());
        int64_t id = message.id();
        //const ::google::protobuf::Message *responsePrototype = &service->GetResponsePrototype(method);
        
        ::google::protobuf::Message * response = service->GetResponsePrototype(method).New();
        // service->CallMethod(method, request, responsePrototype,
        //                     std::bind(&RpcChannel::doneCallback, this, responsePrototype, _1, id));

        //fixit: 第三个参数传递智能指针
        service->CallMethod(method,nullptr,get_pointer(request),response, 
                          NewCallback(this, &RpcChannel::doneCallback, response, id));
                          //std::bind(&RpcChannel::doneCallback, this, response, _1, id))
                          
      }
      else
      {
        // FIXME:
      }
    }
    else
    {
      // FIXME:
    }
  }
  else
  {
    // FIXME:
  }

}


//调用完服务函数之后，最后需要完成的步骤
void RpcChannel::doneCallback(::google::protobuf::Message* response, int64_t id)
{
  // FIXME: can we move serialization to IO thread?
  std::unique_ptr<google::protobuf::Message> d(response);
  okrpc::RpcMessage message;
  message.set_type(RESPONSE);
  message.set_id(id);
  message.set_response(response->SerializeAsString()); // FIXME: error check
  codec_.send(conn_, message);
}
