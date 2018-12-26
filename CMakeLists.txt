cmake_minimum_required(VERSION 3.5)
project (ipfind)

include_directories(./src)
FILE(GLOB_RECURSE INC_ALL "src/*.h")

add_library(ipfind SHARED src/ipv4.cpp src/ipv6.cpp src/ip.cpp ${INC_ALL})
target_include_directories(ipfind PUBLIC ./src)
SET(CMAKE_CXX_FLAGS "${CXX_FLAGS} -march=native -g  -std=c++1y")

#testing
aux_source_directory(./test test)

add_executable(testing test/test.cpp src/ipv4.cpp src/ipv6.cpp src/ip.cpp test/test.cpp ${INC_ALL})



