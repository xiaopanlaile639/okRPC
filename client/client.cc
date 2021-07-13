#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpClient.h>
#include <muduo/net/TcpConnection.h>


//#include <m>
#include "../proto/sudoku.pb.h"
#include "../proto/heartBeat.pb.h"

#include "../RpcChannel.h"

#include <stdio.h>
#include <unistd.h>

using namespace muduo;
using namespace muduo::net;
using namespace okrpc;

class RpcClient 
{
 public:
  RpcClient(EventLoop* loop, const InetAddress& serverAddr)
    : loop_(loop),
      client_(loop, serverAddr, "RpcClient"),
      channel_(new okrpc::RpcChannel),
      stub_(get_pointer(channel_)),
      
      heartBeatStub(get_pointer(channel_))

  {
    client_.setConnectionCallback(
        std::bind(&RpcClient::onConnection, this, _1));
    client_.setMessageCallback(
        std::bind(&okrpc::RpcChannel::onMessage, get_pointer(channel_), _1, _2, _3));
    // client_.enableRetry();
  }

  void connect()
  {
    client_.connect();
  }

 private:
  void onConnection(const TcpConnectionPtr& conn)
  {
    if (conn->connected())
    {
      //channel_.reset(new RpcChannel(conn));
      channel_->setConnection(conn);
      sudoku::SudokuRequest request;
      request.set_checkerboard("001010");
      sudoku::SudokuResponse* response = new sudoku::SudokuResponse();

      stub_.Solve(NULL, &request, response, NewCallback(this, &RpcClient::solved, response));
    }
    else
    {
      loop_->quit();
    }
  }

  void solved(sudoku::SudokuResponse* resp)
  {
        LOG_INFO << "solved:\n" << resp->DebugString();   

        dingdong();


    //client_.disconnect();
  }

    void dingdong(){

        LOG_INFO<<"send dingdong msg....\n";
        heartBeat::HeartBeatRequest req;
        req.set_heartbeartreq("ding dong msg");

        heartBeat::HeartBeatResponse* rsp = new heartBeat::HeartBeatResponse();

        heartBeatStub.HeartBeat(NULL,&req,rsp,NULL);

        client_.disconnect();
    }



  EventLoop* loop_;
  TcpClient client_;
  okrpc::RpcChannelPtr channel_;
  sudoku::SudokuService::Stub stub_;

  heartBeat::HeartBeatService_Stub heartBeatStub;
};

int main(int argc, char* argv[])
{
    muduo::Logger::setLogLevel(muduo::Logger::TRACE );
  LOG_INFO << "pid = " << getpid();
  if (argc > 1)
  {
    EventLoop loop;
    InetAddress serverAddr(argv[1], 9981);

    RpcClient rpcClient(&loop, serverAddr);
    rpcClient.connect();
    loop.loop();
  }
  else
  {
    printf("Usage: %s host_ip\n", argv[0]);
  }
  google::protobuf::ShutdownProtobufLibrary();
}

