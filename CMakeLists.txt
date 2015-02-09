cmake_minimum_required(VERSION 2.8.4)
project(GATrackerpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GATrackerpp.cpp)

add_executable(GATrackerpp ${SOURCE_FILES})

target_link_libraries(GATrackerpp curl)
