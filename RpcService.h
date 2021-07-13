#ifndef MUDUO_PROTORPC2_RPCSERVICE_H
#define MUDUO_PROTORPC2_RPCSERVICE_H


#include "rpcservice.pb.h"


//using namespace okrpc;

namespace okrpc
{
  //class Service;
  typedef ::google::protobuf::Service Service;
  typedef ::std::map<std::string, Service*> ServiceMap;


// the meta service
class RpcServiceImpl : public RpcService
{
public:
  RpcServiceImpl(const ServiceMap* services)
    : services_(services)
  {
  }


  virtual void listRpc(::google::protobuf::RpcController* controller,
                       const ::okrpc::ListRpcRequest* request,
                       ::okrpc::ListRpcResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void getService(::google::protobuf::RpcController* controller,
                       const ::okrpc::GetServiceRequest* request,
                       ::okrpc::GetServiceResponse* response,
                       ::google::protobuf::Closure* done);


  // virtual void listRpc(const ListRpcRequestPtr& request,
  //                      const ListRpcResponse* responsePrototype,
  //                      const RpcDoneCallback& done);

  // virtual void getService(const GetServiceRequestPtr& request,
  //                         const GetServiceResponse* responsePrototype,
  //                         const RpcDoneCallback& done);

private:
  const ServiceMap* services_;
};

}


#endif  // MUDUO_PROTORPC2_RPCSERVICE_H
