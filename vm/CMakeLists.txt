cmake_minimum_required(VERSION 3.28)

project(lox)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCE "*.cpp" "*.h")

add_executable(lox ${SOURCE})