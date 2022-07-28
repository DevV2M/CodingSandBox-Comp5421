cmake_minimum_required(VERSION 3.22)
project(PolymorphPractice)

set(CMAKE_CXX_STANDARD 20)

add_executable(PolymorphPractice main.cpp CommissionEmployee.cpp CommissionEmployee.h BasePlusCommissionEmployee.cpp BasePlusCommissionEmployee.h)
