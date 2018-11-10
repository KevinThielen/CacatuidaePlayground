

add_executable(resources_loader ${CMAKE_CURRENT_SOURCE_DIR}/resources_loader.cpp)

target_include_directories(resources_loader PUBLIC ${PROJECT_SOURCE_DIR}/external/glm/ ${PROJECT_SOURCE_DIR}/external/)
target_link_libraries(resources_loader Common)