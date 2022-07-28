cmake_minimum_required(VERSION 3.22)
project(Assignment04)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment04 ShapeTestDriver.cpp Shape.cpp Shape.h Triangle.cpp Triangle.h Rectangle.cpp Rectangle.h Rhombus.cpp Rhombus.h AcuteTriangle.cpp AcuteTriangle.h RightTriangle.cpp RightTriangle.h Canvas.cpp Canvas.h)
