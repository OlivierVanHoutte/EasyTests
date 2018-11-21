cmake_minimum_required(VERSION 3.12)
project(easyTests)

set(CMAKE_CXX_STANDARD 14)

add_executable(baseExample Examples/basicExample.cpp src/Test.cpp src/Test.h)