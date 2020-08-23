# Version CMake
cmake_minimum_required(VERSION 3.8)

# Project name
project(send_email C CXX)

# Option
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
add_compile_options(
    -Werror
    -Wall
)
endif()

find_package(Poco CONFIG REQUIRED Foundation Net Util)

# Source files
set(SOURCES src/main.cpp)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link target
target_link_libraries(${PROJECT_NAME} PRIVATE Poco::Foundation Poco::Util Poco::Net)