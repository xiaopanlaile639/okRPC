
#include <stdio.h>
#include <unistd.h>

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpClient.h>
#include <muduo/net/TcpConnection.h>

//#include <m>
#include "../proto/sudoku.pb.h"
#include "../proto/heartBeat.pb.h"

#include "../RpcChannel.h"


#include "RpcClient.h"

using namespace muduo;
using namespace muduo::net;
using namespace okrpc;

// class RpcClient :public ::google::protobuf::RpcChannel
// {
// public:
//     RpcClient(EventLoop *loopArg, const InetAddress &serverAddr)
//         : loop(loopArg),
//           //client_(loop, serverAddr, "RpcClient"),
//           channel_(new okrpc::RpcChannel)
//     //stub_(get_pointer(channel_)),

//     // heartBeatStub(get_pointer(channel_))

//     {
//         // client_.setConnectionCallback(
//         //     std::bind(&RpcClient::onConnection, this, _1));
//         // client_.setMessageCallback(
//         //     std::bind(&okrpc::RpcChannel::onMessage, get_pointer(channel_), _1, _2, _3));
//         // // client_.enableRetry();
//     }

//     void connect()
//     {
//         client->connect();
//     }

// private:
//       void onConnection(const TcpConnectionPtr& conn)
//       {
//         if (conn->connected())
//         {
//           //channel_.reset(new RpcChannel(conn));
//             channel_->setConnection(conn);
//             //channel_->CallMethod()

//         //   sudoku::SudokuRequest request;
//         //   request.set_checkerboard("001010");
//         //   sudoku::SudokuResponse* response = new sudoku::SudokuResponse();

//         //   stub_.Solve(NULL, &request, response, NewCallback(this, &RpcClient::solved, response));
//         }
//         else
//         {
//           loop->quit();
//         }
//       }

//     //   void solved(sudoku::SudokuResponse* resp)
//     //   {
//     //         LOG_INFO << "solved:\n" << resp->DebugString();

//     //         dingdong();

//     //     //client_.disconnect();
//     //   }

//     // void dingdong(){

//     //     LOG_INFO<<"send dingdong msg....\n";
//     //     heartBeat::HeartBeatRequest req;
//     //     req.set_heartbeartreq("ding dong msg");

//     //     heartBeat::HeartBeatResponse* rsp = new heartBeat::HeartBeatResponse();

//     //     heartBeatStub.HeartBeat(NULL,&req,rsp,NULL);

//     //     client_.disconnect();
//     // }

//     void CallMethod(const ::google::protobuf::MethodDescriptor *method,
//                     google::protobuf::RpcController *controller,
//                     const ::google::protobuf::Message *request,
//                     ::google::protobuf::Message *response,
//                     ::google::protobuf::Closure *done)
//     {

//         InetAddress serviceAddr;
//         int ret = GetServiceAddr(method->service()->full_name(), serviceAddr);

//         if (ret != 0)
//         {
//             LOG_ERROR << "CallMethod error";
//             return;
//         }



//         /////
//         client = new TcpClient(loop, serviceAddr, "");
     
//         client->setConnectionCallback(
//              std::bind(&RpcClient::onConnection, this, _1));
        
//         client->setMessageCallback(
//             std::bind(&okrpc::RpcChannel::onMessage, get_pointer(channel_), _1, _2, _3));

        
//         channel_->BeforeConnCallMethod(method,controller,request,response,done);

//         connect();



//         //codec_.send(conn_, message);
//     }

//     //通过服务名称获取ZK中的服务地址
//     int GetServiceAddr(std::string serviceName, InetAddress &serviceAddr)
//     {

//         ZkClient zk;
//         zk.start();
//         string path = zk.getRootPath() + "/" + serviceName;

//         string host = zk.get(path.c_str());

//         if (host.empty())
//         {
//             LOG_ERROR << " can't get available server: " << path;
//             return -1;
//         }

//         int idx = host.find(':');
//         string ip = host.substr(0, idx);
//         unsigned short port = atoi(host.substr(idx + 1).c_str();

//         serviceAddr = InetAddress(ip,port);

//         return 0;
//     }

//     struct OutstandingCall
//     {
//         ::google::protobuf::Message *response;
//         ::google::protobuf::Closure *done;
//     };

//     EventLoop *loop;
//     TcpClient *client;
//     okrpc::RpcChannelPtr channel_;
//     // sudoku::SudokuService::Stub stub_;

//     //heartBeat::HeartBeatService_Stub heartBeatStub;
// };

int main(int argc, char *argv[])
{
    muduo::Logger::setLogLevel(muduo::Logger::TRACE);
    LOG_INFO << "pid = " << getpid();
    
    // 
    sudoku::SudokuService_Stub stub(new RpcClient());

    sudoku::SudokuRequest request;
    request.set_checkerboard("001010");
    sudoku::SudokuResponse* response = new sudoku::SudokuResponse();

    stub.Solve(NULL, &request, response, nullptr);

    printf("response:%s",response->DebugString());

    google::protobuf::ShutdownProtobufLibrary();
}
