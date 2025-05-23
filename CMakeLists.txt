cmake_minimum_required(VERSION 3.27)
project(LoxCPP)

set(CMAKE_CXX_STANDARD 17)

file (GLOB SOURCE_FILES src/main.cpp src/Token.cpp)

add_executable(LoxCPP ${SOURCE_FILES})
