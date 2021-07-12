cmake_minimum_required(VERSION 3.5)


project (proto_service_lib)


message(STATUS "in proto_service cmake....")


set(NET_LIB_DIR "/root/myPro/cppPro/build/release-install-cpp11")

include_directories(${NET_LIB_DIR}/include) # 头文件的路径
link_directories( ${NET_LIB_DIR}/lib/) # .a文件的路径


aux_source_directory(. SOURCES3)


add_library(${PROJECT_NAME} ${SOURCES3})
                                
target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    
    ok_rpc_lib
    muduo_net
    muduo_base
    muduo_protobuf_codec
    protobuf
    -lz
)

