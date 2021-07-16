#include "RpcClient.h"


RpcClient::RpcClient(muduo::net::EventLoop* loopArg):
        client(nullptr),
        zk(new ZkClient()),
        loop(loopArg),
        channel_(new okrpc::RpcChannel())
{
    zk->start();
    isConnected = false;

    //设置默认的的回调函数
    setConnectionCallback(std::bind(&RpcClient::onConnection, this, _1));
    setMessageCallback(std::bind(&okrpc::RpcChannel::onMessage, get_pointer(channel_), _1, _2, _3));

    printf("test1..................\n");

}

RpcClient::~RpcClient(){
    zk->close();

}

//通过服务名称获取ZK中的服务地址
int RpcClient::GetServiceAddr(std::string serviceName, InetAddress &serviceAddr)
{

    string path = zk->getRootPath() + "/" + serviceName;

    string host = zk->get(path.c_str());

    printf("get host:%s\n",host.c_str());
    if (host.empty())
    {
        LOG_ERROR << " can't get available server: " << path;
        return -1;
    }

    int idx = host.find(':');
    string ip = host.substr(0, idx);
    unsigned short port = atoi(host.substr(idx + 1).c_str());

    serviceAddr = InetAddress(ip,port);

    return 0;
}

void RpcClient::CallMethod(const ::google::protobuf::MethodDescriptor *method,
                google::protobuf::RpcController *controller,
                const ::google::protobuf::Message *request,
                ::google::protobuf::Message *response,
                ::google::protobuf::Closure *done)
{

    InetAddress serviceAddr;
    //获取服务地址
    int ret = GetServiceAddr(method->service()->full_name(), serviceAddr);

    if (ret != 0)
    {
        LOG_ERROR << "CallMethod error";
        return;
    }

    if(client == nullptr){
        
        client = std::make_unique<TcpClient>(loop,serviceAddr,"tcpClient");
        //client = new TcpClient(loop, serviceAddr, "tcpClient");

        client->setConnectionCallback(connectionCallback_);

        client->setMessageCallback(messageCallback_);

        channel_->BeforeConnCallMethod(method,controller,request,response,done);
        connect();

       
    }else{
        
        if(isConnected){
            //在已经建立连接的情况下调用方法
            channel_->CallMethodWithConn(method,controller,request,response,done);
        }else{
            printf("connection do not established!\n");
        }
       
    }

}


void RpcClient::setConnection(const TcpConnectionPtr& conn){
    channel_->setConnection(conn);
}

void RpcClient::onConnection(const TcpConnectionPtr& conn)
{
  if (conn->connected())
  {
      isConnected = true;       //连接成功
      channel_->setConnection(conn);
      channel_->AfterConnCallMethod(conn);          //发送消息

  }
  else
  {
    loop->quit();
  }
}