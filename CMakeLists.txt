cmake_minimum_required(VERSION 3.5)

project (ok_rpc_lib)


message(STATUS "in lib cmake....")


set(NET_LIB_DIR "../muduoRPC_all/build/release-install-cpp11")

include_directories(${NET_LIB_DIR}/include) # 头文件的路径
link_directories( ${NET_LIB_DIR}/lib/) # .a文件的路径

aux_source_directory(. SOURCES)

#编译成为库文件
add_library(${PROJECT_NAME} ${SOURCES})

SET( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -O3  -pthread")
                                                      
target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    muduo_net
    muduo_base
    muduo_protobuf_codec
    protobuf
    -lz
)


add_subdirectory(proto)
# add_subdirectory(rpcbench)
add_subdirectory(server)
add_subdirectory(client)

