cmake_minimum_required(VERSION 3.5)


project (rpcbench)


message(STATUS "in rpcbench cmake....")

set(NET_LIB_DIR "/root/myPro/cppPro/build/release-install-cpp11")

add_executable(rpcbench_server server.cc)
target_link_libraries( rpcbench_server
    
    ok_rpc_lib
    proto_service_lib
    muduo_net
    muduo_base
    muduo_protobuf_codec
    protobuf
    -lz
)


add_executable(rpcbench_client client.cc)
target_link_libraries( rpcbench_client
    
    ok_rpc_lib
    proto_service_lib
    muduo_net
    muduo_base
    muduo_protobuf_codec
    protobuf
    -lz
)

include_directories(${NET_LIB_DIR}/include) # 头文件的路径
link_directories( ${NET_LIB_DIR}/lib/) # .a文件的路径


                                
# target_include_directories(${PROJECT_NAME}
#     PUBLIC 
#         ${PROJECT_BINARY_DIR}
# )

# target_link_libraries( ${PROJECT_NAME}
    
#     ok_rpc_lib
#     proto_service_lib
#     muduo_net
#     muduo_base
#     muduo_protobuf_codec
#     protobuf
#     -lz
# )

