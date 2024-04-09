cmake_minimum_required(VERSION 3.16)
project(SPEL VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

add_executable(SPEL main.cpp)
target_link_libraries(SPEL PRIVATE SDL2::SDL2)



