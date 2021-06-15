#ifndef OKPRC_CODE_H
#define OKPRC_CODE_H

#include <muduo/base/Timestamp.h>
#include <muduo/net/protobuf/ProtobufCodecLite.h>

namespace okrpc
{
class muduo::net::Buffer;
class muduo::net::TcpConnection;
typedef std::shared_ptr<muduo::net::TcpConnection> TcpConnectionPtr;

class RpcMessage;
typedef std::shared_ptr<RpcMessage> RpcMessagePtr;
extern const char rpctag[];// = "RPC0";
//const char rpctag[] = "RPC0";

// wire format
//
// Field     Length  Content
//
// size      4-byte  N+8
// "RPC0"    4-byte
// payload   N-byte
// checksum  4-byte  adler32 of "RPC0"+payload
//

typedef muduo::net::ProtobufCodecLiteT<RpcMessage, rpctag> RpcCodec;

}  //okrpc

#endif