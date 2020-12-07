cmake_minimum_required(VERSION 3.2)
project(protobuf_tutorial)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
find_package(Protobuf REQUIRED)

set(SRC_LIST 
    example.pb.cc 
    protobuf_encoding.cc)


add_executable(encoding ${SRC_LIST})
target_include_directories(encoding PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(encoding ${PROTOBUF_LIBRARIES})