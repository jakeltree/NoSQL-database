cmake_minimum_required(VERSION 2.8) 

project(task3_client)				

set(SOURCE_EXE src/main_client.cpp)
set(SOURCE_LIB src/task3_client.cpp)
include_directories(inc)

add_library(task_client STATIC ${SOURCE_LIB})
add_executable(main_client ${SOURCE_EXE})
target_link_libraries(main_client task_client)