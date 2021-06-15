# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (rpc_server)

# Create a sources variable with a link to all cpp files to compile
# set(SOURCES
#     src/Hello.cpp
#     src/main.cpp
# )

message(STATUS "in server cmake....")

# find_package(ProtocolBuffers) 


set(NET_LIB_DIR "/root/myPro/cppPro/build/release-install-cpp11")

include_directories(${NET_LIB_DIR}/include) # 头文件的路径
link_directories( ${NET_LIB_DIR}/lib/) # .a文件的路径


aux_source_directory(. SOURCES)

message(STATUS "sources:" ${SOURCES})


#add_executable(${PROJECT_NAME} RpcChannel.cc RpcService.cc rpc.pb.cc rpcservice.pb.cc server.cc sudoku.pb.cc)
add_executable(${PROJECT_NAME} ${SOURCES})
#设置编译选项

# set(CXX_FLAGS
#  -g
#  # -DVALGRIND
#  # -DMUDUO_STD_STRING
#  -Wall
#  -Wextra
#  # -m32
#  -Werror
#  -Wconversion
#  -Wno-unused-parameter
#  -Wold-style-cast
#  -Woverloaded-virtual
#  -Wpointer-arith
#  -Wno-error=shadow
#  -Wwrite-strings
#  -march=native
#  # -MMD
#  -std=c++11
#  )
# string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

SET( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -rdynamic -g -march=native  -Wall -Wextra  -lstdc++  -Wconversion  -Wno-unused-parameter -Wold-style-cast  -Wpointer-arith -Wno-error=shadow -Wwrite-strings -std=c++11 -O3  -pthread")
                                           
                                         
                                         
                                        
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        

#SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${PROJECT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    #hello_net_lib
    muduo_net
    muduo_base
    muduo_protobuf_codec
    #muduo_protorpc_wire
    #muduo_protobufrpc
    protobuf
    -lz
)

