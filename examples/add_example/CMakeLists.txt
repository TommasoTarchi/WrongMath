cmake_minimum_required(VERSION 3.15)
project(add_example)

add_executable(add_example add_example.cpp)
target_include_directories(add_example PRIVATE ${CMAKE_SOURCE_DIR}/../../include)
target_link_directories(add_example PRIVATE ${CMAKE_SOURCE_DIR}/../../build)
target_link_libraries(add_example wrong_math)
