set(example_name "net_brawlers")
file(GLOB example_src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(${example_name}  ${example_src})


target_include_directories(${example_name} PUBLIC ${PROJECT_SOURCE_DIR}/external/glm/ ${PROJECT_SOURCE_DIR}/external/)
set_target_properties(${example_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/${example_name}") 
target_link_libraries(${example_name} Common)