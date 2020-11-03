# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(send_email)

# Options
set(CMAKE_CXX_STANDARD 17)

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror
        -Wall
    )
endif()

find_package(Poco CONFIG REQUIRED Foundation Net Util)

# Source files
set(SOURCES
    source/main.cpp
)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link target
target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Foundation Poco::Util Poco::Net)
