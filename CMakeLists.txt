cmake_minimum_required(VERSION 3.0)
project(Planning)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CPUPlanning.cpp CPUPlanning.h cxxopts.hpp)
add_executable(Planning ${SOURCE_FILES})