// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is a public header file, it must only include public header files.

#ifndef MUDUO_PROTORPC2_RPCSERVER_H
#define MUDUO_PROTORPC2_RPCSERVER_H

#include <muduo/net/TcpServer.h>
#include <RpcService.h>

using namespace muduo::net;



class Service;

namespace okrpc
{

class RpcServer
{
 public:
  RpcServer(EventLoop* loop,
            const InetAddress& listenAddr);

  void setThreadNum(int numThreads)
  {
    server_.setThreadNum(numThreads);
  }

  // NOT thread safe, must call before start().
  void registerService(Service*);
  void start();

 private:
  void onConnection(const TcpConnectionPtr& conn);

  // void onMessage(const TcpConnectionPtr& conn,
  //                Buffer* buf,
  //                Timestamp time);

  EventLoop* loop_;
  TcpServer server_;
  std::map<std::string, Service*> services_;
  RpcServiceImpl metaService_;
};

}

#endif  // MUDUO_NET_PROTORPC2_RPCSERVER_H