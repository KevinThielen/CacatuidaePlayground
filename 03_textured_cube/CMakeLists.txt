

add_executable(textured_cube ${CMAKE_CURRENT_SOURCE_DIR}/textured_cube.cpp)

target_include_directories(textured_cube PUBLIC ${PROJECT_SOURCE_DIR}/external/glm/)
target_link_libraries(textured_cube Common)