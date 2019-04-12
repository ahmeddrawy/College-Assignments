cmake_minimum_required(VERSION 3.10)
project(Assignment_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment_3 main.cpp)
add_executable(Problem1 "Problem 1/main.cpp" "Problem 1/LinkedList.h" "Problem 1/Node.h")