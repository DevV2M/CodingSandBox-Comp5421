cmake_minimum_required(VERSION 3.22)
project(Assignment05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment05
        assignment5.h
        assignment_5_test_driver.cpp assignment5.cpp)
