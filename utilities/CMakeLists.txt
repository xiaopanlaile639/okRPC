cmake_minimum_required(VERSION 3.5)

project (rpc_zk_lib)

message(STATUS "in ZK cmake....")

set(NET_LIB_DIR "../../muduoRPC_all/build/release-install-cpp11")

include_directories(${NET_LIB_DIR}/include) # 头文件的路径
link_directories( ${NET_LIB_DIR}/lib/) # .a文件的路径

set(SOURCES4 "ZkClient.cpp")
# aux_source_directory(ZkClient.cpp SOURCES4)

add_library(${PROJECT_NAME}  ${SOURCES4})

                                                                                            
target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    zookeeper_mt
    pthread
)

