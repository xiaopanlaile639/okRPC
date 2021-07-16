#include <muduo/base/Logging.h>
#include <google/protobuf/descriptor.h>
#include <muduo/net/TcpConnection.h>

#include "RpcServer.h"
#include "RpcChannel.h"

using namespace muduo;
using namespace muduo::net;
using namespace okrpc;

//服务的IP
const static std::string SERVER_IP = "127.0.0.1:9981";

RpcServer::RpcServer(EventLoop *loop,
                     const InetAddress &listenAddr)
    : loop_(loop),
      server_(loop, listenAddr, "RpcServer"),
      services_(),
      metaService_(&services_)
{
    server_.setConnectionCallback(
        std::bind(&RpcServer::onConnection, this, _1));
    //   server_.setMessageCallback(
    //       std::bind(&RpcServer::onMessage, this, _1, _2, _3));

    //启动ZK客户端
    zkClient.start();
    //发送心跳消息
    //todo: 在一个连接中发送心跳消息和注册消息
    zkClient.sendheartBeat();

    //注册原始服务
    registerService(&metaService_);
}


//在ZK中创建服务
void RpcServer::CreateServiceInZK(std::string serviceName){
    string rootPath = zkClient.getRootPath();

    string servicePath = rootPath+"/"+serviceName;
    
    printf("create node (%s) in zk....\n",servicePath.c_str());
    //创建临时结点  serverName->IP:PORT
    zkClient.create(servicePath.c_str(),SERVER_IP.c_str(),SERVER_IP.size(),ZOO_EPHEMERAL);


}

void RpcServer::registerService(Service *service)
{
    const google::protobuf::ServiceDescriptor *desc = service->GetDescriptor();
    services_[desc->full_name()] = service;

    CreateServiceInZK(desc->full_name());

}

void RpcServer::start()
{
    server_.start();
}

void RpcServer::onConnection(const TcpConnectionPtr &conn)
{
    LOG_INFO << "RpcServer - " << conn->peerAddress().toIpPort() << " -> "
             << conn->localAddress().toIpPort() << " is "
             << (conn->connected() ? "UP" : "DOWN");

    if (conn->connected())
    {
        //todo: 栈空间，空间不会被释放掉吗？
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
