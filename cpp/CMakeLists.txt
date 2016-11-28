cmake_minimum_required(VERSION 3.6)
project(cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        all_tests.cpp
        all_tests.hpp
        tennis1.cc
#        tennis2.cc
#        tennis3.cc
        test_suite.tests.cpp)

add_custom_target(cpp COMMAND make ${cpp_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_executable(run.tests ${SOURCE_FILES})