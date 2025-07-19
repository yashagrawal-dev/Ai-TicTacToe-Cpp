cmake_minimum_required(VERSION 3.10)
project(AI_TicTacToe_Cpp)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Output directory for binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(AI_TicTacToe ${SOURCES})
