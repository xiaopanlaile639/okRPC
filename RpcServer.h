#ifndef MUDUO_PROTORPC2_RPCSERVER_H
#define MUDUO_PROTORPC2_RPCSERVER_H

#include <muduo/net/TcpServer.h>

#include "RpcService.h"
#include "utilities/ZkClient.h"

using namespace muduo::net;

class Service;

namespace okrpc
{


//todo: 单实例
class RpcServer
{
public:
    RpcServer(EventLoop *loop,
                const InetAddress &listenAddr);

    void setThreadNum(int numThreads)
    {
        server_.setThreadNum(numThreads);
    }

    // NOT thread safe, must call before start().
    void registerService(Service *);
    void start();



private:

    void CreateServiceInZK(std::string serviceName);

    void onConnection(const TcpConnectionPtr &conn);

    // void onMessage(const TcpConnectionPtr& conn,
    //                Buffer* buf,
    //                Timestamp time);

    EventLoop *loop_;
    TcpServer server_;
    std::map<std::string, Service *> services_;
    RpcServiceImpl metaService_;

    ZkClient zkClient;          //含有一个ZooKeeper实例

};

}

#endif // MUDUO_NET_PROTORPC2_RPCSERVER_H
