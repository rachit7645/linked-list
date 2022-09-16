cmake_minimum_required(VERSION 3.0.0)
project(linkedList VERSION 0.1.0)

# MSVC is not supported
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(FATAL_ERROR "Only GCC/Clang are supported")
endif()

# Require C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
add_library(linkedList
    Node.cpp
)

# Define _DEBUG in debug mode
target_compile_definitions(linkedList PRIVATE _DEBUG)
# Enable all warnings
target_compile_options(linkedList PRIVATE -Wall)
# Enable extra warnings
target_compile_options(linkedList PRIVATE -Wextra)
# Enable pedantic warnings
target_compile_options(linkedList PRIVATE -Wpedantic)
# -O3 optimisations
target_compile_options(linkedList PRIVATE -O3)
# Enable debug output
target_compile_options(linkedList PRIVATE -g)

# Test executables
add_executable(BasicTest tests/BasicNode.cpp)
target_link_libraries(BasicTest linkedList)

enable_testing()
add_test(BasicNodeTest BasicTest)