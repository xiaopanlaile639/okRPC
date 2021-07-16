
#include <stdio.h>
#include <unistd.h>

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpClient.h>
#include <muduo/net/TcpConnection.h>

#include "../proto/sudoku.pb.h"
#include "../proto/heartBeat.pb.h"

#include "../RpcChannel.h"

#include "RpcClient.h"

#include <thread>


using namespace muduo;
using namespace muduo::net;
using namespace okrpc;

void solved(sudoku::SudokuResponse* resp)
{
    LOG_INFO << "solved:\n" << resp->DebugString();
}


void dingdong(heartBeat::HeartBeatResponse * rsp){
    LOG_INFO<<"send dingdong msg [ "<<rsp->DebugString()<<" ] ok.\n";
}


int main(int argc, char *argv[])
{
    muduo::Logger::setLogLevel(muduo::Logger::TRACE);
    LOG_INFO << "pid = " << getpid();
    
    EventLoop loop;
    RpcClient * client = new RpcClient(&loop);
    
    printf("send sodu request\n");
    //发送sodu Msg
    sudoku::SudokuService_Stub stub(client);
    sudoku::SudokuRequest request;
    request.set_checkerboard("001010");
    sudoku::SudokuResponse* response = new sudoku::SudokuResponse();
    stub.Solve(NULL, &request, response, 
            NewCallback(&solved, response));


    std::thread t([&] (){
        
        printf("thread sleep....\n");
        sleep(5);

        printf("send heartBeat request\n");
        //发送心跳消息
        heartBeat::HeartBeatService_Stub heartBeatStub(client);
        heartBeat::HeartBeatRequest heartBeatReq;
        heartBeatReq.set_heartbeartreq("ding dong msg\n");
        heartBeat::HeartBeatResponse * heartBeatRsp = new heartBeat::HeartBeatResponse();
        heartBeatStub.HeartBeat(nullptr,&heartBeatReq,heartBeatRsp, 
            NewCallback(&dingdong, heartBeatRsp));

    });
    


    printf("send request end...");

    loop.loop();
    //

    google::protobuf::ShutdownProtobufLibrary();
}
