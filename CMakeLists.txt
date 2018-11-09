cmake_minimum_required(VERSION 3.0)
project(CacatuidaePlayground VERSION 0.0.1 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

add_definitions(-Wall -Wcast-qual -Wextra -Wshadow -fno-exceptions -fno-rtti -pedantic -flto -m64)
set (CMAKE_EXECUTABLE_SUFFIX ".html")


#common lib
add_library(Common INTERFACE)
target_include_directories(Common INTERFACE ${CMAKE_CURRENT_LIST_DIR}/common/)

#examples
add_subdirectory(01_hello_triangle)
add_subdirectory(02_indexed_plane)
