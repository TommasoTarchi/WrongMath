cmake_minimum_required(VERSION 3.15)
project(WrongMath VERSION 1.0.0 LANGUAGES CXX)

# require minimum c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define shared library
add_library(WrongMath SHARED 
    src/wrong_sum.cpp
)

# include directories
target_include_directories(WrongMath PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# set output library name
set_target_properties(WrongMath PROPERTIES OUTPUT_NAME "wrong_math")

# enable CMake testing functionality
enable_testing()

# define executable for unit testing
add_executable(unit_tests.x tests/unit_tests_main.cpp)

# link test executable to library
target_link_libraries(unit_tests.x PRIVATE WrongMath)

# register test (so that CTest can find it)
add_test(NAME WrongMathUnitTests COMMAND unit_tests.x)
