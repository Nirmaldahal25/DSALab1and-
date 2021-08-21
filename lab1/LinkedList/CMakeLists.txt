cmake_minimum_required(VERSION 3.10)

project(linkedlist)

include_directories(include)

set(HEADER_FILE ./include/LinkedList.hpp)

add_executable(${PROJECT_NAME} ./src/LinkedList.cpp)