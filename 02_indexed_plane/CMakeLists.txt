add_executable(indexed_plane ${CMAKE_CURRENT_SOURCE_DIR}/indexed_plane.cpp)

target_include_directories(indexed_plane PUBLIC ${PROJECT_SOURCE_DIR}/external/glm/)
target_link_libraries(indexed_plane Common)