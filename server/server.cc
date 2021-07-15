#include <unistd.h>

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/protorpc/RpcServer.h>

#include "../proto/sudoku.pb.h"
#include "../RpcServer.h"
#include "../proto/heartBeat.pb.h"

using namespace muduo;
using namespace muduo::net;
using namespace heartBeat;
using namespace sudoku;


class SudokuServiceImpl : public SudokuService
{
 public:
  virtual void Solve(::google::protobuf::RpcController* controller,
                       const ::sudoku::SudokuRequest* request,
                       ::sudoku::SudokuResponse* response,
                       ::google::protobuf::Closure* done)
  {
    LOG_INFO << "SudokuServiceImpl::Solve";
    response->set_solved(true);
    response->set_checkerboard("1234567");
    done->Run();
  }
};


class HeartBeatServiceImpl: public HeartBeatService
{
public:
    virtual void HeartBeat(::google::protobuf::RpcController* controller,
                        const ::heartBeat::HeartBeatRequest* request,
                        ::heartBeat::HeartBeatResponse* response,
                        ::google::protobuf::Closure* done)
    {
        LOG_INFO << "HeartBeatServiceImpl::HeartBeat, receive heartbeat msg: "<< request->heartbeartreq();
      
        response->set_heartbeartrsp("receive heart beat");
        done->Run();
    }

};


int main()
{
    muduo::Logger::setLogLevel(muduo::Logger::TRACE );
    
    LOG_INFO << "pid = " << getpid();
    
    EventLoop loop;
    InetAddress listenAddr(9981);
    SudokuServiceImpl impl;

    HeartBeatServiceImpl impl1;

    okrpc::RpcServer server(&loop, listenAddr);
  
    
    server.registerService(&impl);
    server.registerService(&impl1);

    server.start();
    loop.loop();
    google::protobuf::ShutdownProtobufLibrary();
}

