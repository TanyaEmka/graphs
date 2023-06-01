cmake_minimum_required(VERSION 3.16.3)
project(Graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(lib)

target_include_directories(${PROJECT_NAME} PUBLIC ${GRAPHS_LIB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${GRAPHS_LIB_LIBRARIES})
