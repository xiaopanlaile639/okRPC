# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 2.8)

# Set the project name
project (rpc_server)

# Create a sources variable with a link to all cpp files to compile
# set(SOURCES
#     src/Hello.cpp
#     src/main.cpp
# )

message(STATUS "in server cmake....")

# find_package(ProtocolBuffers) 


set(NET_LIB_DIR "/root/myPro/cppPro/build/release-install-cpp11/include/")

include_directories(${NET_LIB_DIR}) # 头文件的路径
link_directories( ${NET_LIB_DIR}/lib/) # .a文件的路径


aux_source_directory(. SOURCES)

#set(SOURCES ../rpc_meta.pb.cc echo_service.pb.cc rpc_server_impl.cpp server.cpp)
# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES})

#设置编译选项
SET( CMAKE_CXX_FLAGS "-std=c++11 -O3")
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    #hello_net_lib
    muduo_net
    muduo_base
    #muduo_protobufrpc
    protobuf
)

