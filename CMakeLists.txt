cmake_minimum_required(VERSION 3.15)
project(WrongMath VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define shared library
add_library(WrongMath SHARED 
    src/wrong_sum.cpp
)

# include directories
target_include_directories(WrongMath PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/wrong_math>
    $<INSTALL_INTERFACE:include/wrong_math>
)

# set output library name
set_target_properties(WrongMath PROPERTIES OUTPUT_NAME "wrong_math")
