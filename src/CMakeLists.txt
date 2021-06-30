cmake_minimum_required(VERSION 3.10)
project(cubiomes_template)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 14)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2 -static-libgcc")
set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} -static-libgcc -static-libstdc++ -static -pthread -Wl,--whole-archive -lpthread -Wl,--no-whole-archive")
add_definitions("-DCPP_SRC_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/\"")


add_subdirectory(modules)
add_subdirectory(src)
