cmake_minimum_required(VERSION 2.8) 

project(task3_server)				

set(SOURCE_EXE src/main_server.cpp)
set(SOURCE_LIB src/task3_server.cpp)
include_directories(inc)

add_library(task_server STATIC ${SOURCE_LIB})
add_executable(main_server ${SOURCE_EXE})
target_link_libraries(main_server task_server)