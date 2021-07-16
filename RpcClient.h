#ifndef RPC_CLIENT_H
#define RPC_CLIENT_H


#include <stdio.h>
#include <unistd.h>

#include <google/protobuf/stubs/common.h> // implicit_cast, down_cast
#if GOOGLE_PROTOBUF_VERSION >= 3000000
#include <google/protobuf/stubs/casts.h> // implicit_cast, down_cast
#endif

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpClient.h>
#include <muduo/net/TcpConnection.h>

#include "RpcService.h"
#include "RpcChannel.h"
#include "utilities/ZkClient.h"

using namespace muduo;
using namespace muduo::net;
using namespace okrpc;


class RpcClient :public ::google::protobuf::RpcChannel
{
public:
    RpcClient(muduo::net::EventLoop* loopArg);

    ~RpcClient();

    void connect()
    {
        client->connect();
    }

    void CallMethod(const ::google::protobuf::MethodDescriptor *method,
                google::protobuf::RpcController *controller,
                const ::google::protobuf::Message *request,
                ::google::protobuf::Message *response,
                ::google::protobuf::Closure *done)override;

    void onConnection(const TcpConnectionPtr& conn);
private:
    
    //通过服务名称获取ZK中的服务地址
    int GetServiceAddr(std::string serviceName, InetAddress &serviceAddr);

    struct OutstandingCall
    {
        ::google::protobuf::Message *response;
        ::google::protobuf::Closure *done;
    };

    //TcpClient *client;
    std::unique_ptr<TcpClient> client;
    okrpc::RpcChannelPtr channel_;
    EventLoop *loop;

    std::unique_ptr<ZkClient> zk;
    //ZkClient *zk;
    bool isConnected;           //是否已经和客户端建立连接

    //heartBeat::HeartBeatService_Stub heartBeatStub;
};


#endif