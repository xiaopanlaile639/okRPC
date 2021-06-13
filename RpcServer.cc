


#include <muduo/base/Logging.h>
#include <google/protobuf/descriptor.h>
#include <muduo/net/TcpConnection.h>

#include "RpcServer.h"
#include "RpcChannel.h"
#include "service.h"


using namespace muduo;
using namespace muduo::net;
using namespace okrpc;

RpcServer::RpcServer(EventLoop* loop,
                     const InetAddress& listenAddr)
  : loop_(loop),
    server_(loop, listenAddr, "RpcServer"),
    services_(),
    metaService_(&services_)
{
  server_.setConnectionCallback(
      std::bind(&RpcServer::onConnection, this, _1));
//   server_.setMessageCallback(
//       std::bind(&RpcServer::onMessage, this, _1, _2, _3));

  registerService(&metaService_);
}

void RpcServer::registerService(Service* service)
{
  const google::protobuf::ServiceDescriptor* desc = service->GetDescriptor();
  services_[desc->full_name()] = service;
}

void RpcServer::start()
{
  server_.start();
}

void RpcServer::onConnection(const TcpConnectionPtr& conn)
{
  LOG_INFO << "RpcServer - " << conn->peerAddress().toIpPort() << " -> "
    << conn->localAddress().toIpPort() << " is "
    << (conn->connected() ? "UP" : "DOWN");


  if (conn->connected())
  {
    RpcChannelPtr channel(new RpcChannel(conn));
    
    channel->setServices(&services_);

    ///fixit
    conn->setMessageCallback(
        std::bind(&RpcChannel::onMessage, get_pointer(channel), _1, _2, _3));
    
    conn->setContext(channel);
  }
  else
  {
    conn->setContext(RpcChannelPtr());
    // FIXME:
  }
}

// void RpcServer::onMessage(const TcpConnectionPtr& conn,
//                           Buffer* buf,
//                           Timestamp time)
// {
//   RpcChannelPtr& channel = boost::any_cast<RpcChannelPtr&>(conn->getContext());
//   channel->onMessage(conn, buf, time);
// }

