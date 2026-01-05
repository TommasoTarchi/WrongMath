cmake_minimum_required(VERSION 3.15)
project(WrongMath VERSION 1.0.0 LANGUAGES CXX)

# require minimum c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


### compile library ###

# define shared library
add_library(WrongMath SHARED 
    src/wrong_sum.cpp
    src/wrong_diff.cpp
)

# include directories
target_include_directories(WrongMath PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# set output library name
set_target_properties(WrongMath PROPERTIES OUTPUT_NAME "wrong_math")


### test library ###

# download and include Catch2
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # Pin a specific version for stability
)

FetchContent_MakeAvailable(Catch2)

# enable CMake testing functionality
enable_testing()

# define executable for unit testing
add_executable(unit_tests.x tests/unit_tests_main.cpp)

# link library and Catch2 to executable
target_link_libraries(unit_tests.x PRIVATE 
    WrongMath 
    Catch2::Catch2WithMain
)

# auto-register tests with CTest
include(Catch)

catch_discover_tests(unit_tests.x)

### generate documentation ###

# find Doxygen package
find_package(Doxygen)

if (DOXYGEN_FOUND)

    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # configure file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message(STATUS "Doxygen build started")

    # add custom target for documentation
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

else (DOXYGEN_FOUND)

    message(WARNING "Doxygen not found, documentation will not be generated")

endif (DOXYGEN_FOUND)
