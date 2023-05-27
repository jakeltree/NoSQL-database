cmake_minimum_required(VERSION 2.8) 

project(task3)

include_directories(task3_server)
include_directories(task3_client)
include_directories(ext)
configure_file(data/generate_data.json data/generate_data.json @ONLY)
configure_file(data/test.json data/test.json @ONLY)

add_subdirectory(task3_server)
add_subdirectory(task3_client)
