cmake_minimum_required(VERSION 3.15)
project(Snake)

set(CMAKE_CXX_STANDARD 17)




add_executable(Snake main.cpp Point.h Point.cpp Snake.cpp Snake.h Menu.cpp Menu.h)

