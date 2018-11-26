cmake_minimum_required(VERSION 3.0)
project(CacatuidaePlayground VERSION 0.0.1 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 11)

add_definitions(-Wall -Wcast-qual -Wextra -Wshadow -fno-exceptions -fno-rtti -pedantic -flto -m64 -pedantic)
set (CMAKE_EXECUTABLE_SUFFIX ".html")
set(PROJECT_BINARY_DIR ${CMAKE_CURRENT_LIST_DIR}/bin)
set(EMSCRIPTEN 1)

#common lib
FILE(GLOB_RECURSE common_source ${CMAKE_CURRENT_LIST_DIR}/common/*.cpp)
add_library(Common ${common_source})
target_include_directories(Common PUBLIC ${CMAKE_CURRENT_LIST_DIR}/common/ ${CMAKE_CURRENT_LIST_DIR}/external/glm)

#examples
add_subdirectory(06_net_brawlers)
#add_subdirectory(02_indexed_plane)
#add_subdirectory(03_textured_cube)
#add_subdirectory(04_resources_loader)
#add_subdirectory(05_draw_geometry)
