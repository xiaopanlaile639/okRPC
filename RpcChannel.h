#ifndef MUDUO_PROTORPC2_RPCCHANNEL_H
#define MUDUO_PROTORPC2_RPCCHANNEL_H

#include <google/protobuf/stubs/common.h> // implicit_cast, down_cast
#if GOOGLE_PROTOBUF_VERSION >= 3000000
#include <google/protobuf/stubs/casts.h> // implicit_cast, down_cast
#endif

#include <map>
 
#include <muduo/base/Atomic.h>
#include <muduo/base/Mutex.h>

#include <muduo/net/TcpConnection.h>
#include <muduo/net/Callbacks.h>

#include "RpcService.h"
#include "RpcCodec.h"

namespace google
{
  namespace protobuf
  {

    // Defined in other files.
    class Descriptor;        // descriptor.h
    class ServiceDescriptor; // descriptor.h
    class MethodDescriptor;  // descriptor.h
    class Message;           // message.h
    typedef ::std::shared_ptr<Message> MessagePtr;

    // When you upcast (that is, cast a pointer from type Foo to type
    // SuperclassOfFoo), it's fine to use implicit_cast<>, since upcasts
    // always succeed.  When you downcast (that is, cast a pointer from
    // type Foo to type SubclassOfFoo), static_cast<> isn't safe, because
    // how do you know the pointer is really of type SubclassOfFoo?  It
    // could be a bare Foo, or of type DifferentSubclassOfFoo.  Thus,
    // when you downcast, you should use this macro.  In debug mode, we
    // use dynamic_cast<> to double-check the downcast is legal (we die
    // if it's not).  In normal mode, we do the efficient static_cast<>
    // instead.  Thus, it's important to test in debug mode to make sure
    // the cast is legal!
    //    This is the only place in the code we should use dynamic_cast<>.
    // In particular, you SHOULDN'T be using dynamic_cast<> in order to
    // do RTTI (eg code like this:
    //    if (dynamic_cast<Subclass1>(foo)) HandleASubclass1Object(foo);
    //    if (dynamic_cast<Subclass2>(foo)) HandleASubclass2Object(foo);
    // You should design the code some other way not to need this.

    template <typename To, typename From> // use like this: down_pointer_cast<T>(foo);
    inline ::std::shared_ptr<To> down_pointer_cast(const ::std::shared_ptr<From> &f)
    {
      // so we only accept smart pointers
      // Ensures that To is a sub-type of From *.  This test is here only
      // for compile-time type checking, and has no overhead in an
      // optimized build at run-time, as it will be optimized away
      // completely.
      if (false)
      {
        implicit_cast<const From *, To *>(0);
      }

#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
      assert(f == NULL || dynamic_cast<To *>(muduo::get_pointer(f)) != NULL); // RTTI: debug mode only!
#endif
      return ::std::static_pointer_cast<To>(f);
    }

  } // namespace protobuf
} // namespace google

 

using namespace muduo;
using namespace muduo::net;

namespace okrpc
{

  class RpcController;
  //class Service;


//fixit: 是否需要继承自google::RpcChannel
  class RpcChannel :public ::google::protobuf::RpcChannel
  {
  public:
    typedef std::map<std::string, Service *> ServiceMap;

    RpcChannel();

    explicit RpcChannel(const TcpConnectionPtr &conn);

    ~RpcChannel();

    void setConnection(const TcpConnectionPtr &conn)
    {
      conn_ = conn;
    }

    const ServiceMap *getServices() const
    {
      return services_;
    }

    void setServices(const ServiceMap *services)
    {
      services_ = services;
    }

    
    void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done) override;
    
    
   // typedef ::std::function<void(const ::google::protobuf::MessagePtr &)> ClientDoneCallback;

    // Call the given method of the remote service.  The signature of this
    // procedure looks the same as Service::CallMethod(), but the requirements
    // are less strict in one important way:  the request and response objects
    // need not be of any specific class as long as their descriptors are
    // method->input_type() and method->output_type().
    // void CallMethod(const ::google::protobuf::MethodDescriptor *method,
    //                 const ::google::protobuf::Message &request,
    //                 const ::google::protobuf::Message *response,
    //                 const ClientDoneCallback &done);

    // template <typename Output>
    // static void downcastcall(const ::std::function<void(const std::shared_ptr<Output> &)> &done,
    //                          const ::google::protobuf::MessagePtr &output)
    // {
    //   done(::google::protobuf::down_pointer_cast<Output>(output));
    // }

    // template <typename Output>
    // void CallMethod(const ::google::protobuf::MethodDescriptor *method,
    //                 const ::google::protobuf::Message &request,
    //                 const Output *response,
    //                 const ::std::function<void(const std::shared_ptr<Output> &)> &done)
    // {
    //   CallMethod(method, request, response, std::bind(&downcastcall<Output>, done, _1));
    // }

    void onDisconnect();

    void onMessage(const TcpConnectionPtr &conn,
                   Buffer *buf,
                   Timestamp receiveTime);

  private:
    void onRpcMessage(const TcpConnectionPtr &conn,
                      const RpcMessagePtr &messagePtr,
                      Timestamp receiveTime);

    void callServiceMethod(const RpcMessage &message);
    
    //发送完数据之后的回调函数
    void doneCallback(::google::protobuf::Message* response, int64_t id);

    struct OutstandingCall
    {
      ::google::protobuf::Message* response;
      ::google::protobuf::Closure* done;
    };

    RpcCodec codec_;
    TcpConnectionPtr conn_;
    AtomicInt64 id_;

    MutexLock mutex_;
    std::map<int64_t, OutstandingCall> outstandings_;

    const ServiceMap *services_;
  };


  typedef std::shared_ptr<RpcChannel> RpcChannelPtr; // FIXME: unique_ptr

}


#endif // MUDUO_PROTORPC2_RPCCHANNEL_H
