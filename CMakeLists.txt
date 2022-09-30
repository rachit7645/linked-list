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
    List.cpp
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

# iterator Test
add_executable(Iterator tests/Iterator.cpp)
target_link_libraries(Iterator linkedList)
# Reverse iterator Test
add_executable(RevIterator tests/RevIterator.cpp)
target_link_libraries(RevIterator linkedList)
# Const iterator Test
add_executable(ConstIterator tests/ConstIterator.cpp)
target_link_libraries(ConstIterator linkedList)
# Const Reverse iterator Test
add_executable(ConstRevIterator tests/ConstRevIterator.cpp)
target_link_libraries(ConstRevIterator linkedList)
# list lib test
add_executable(ListLib tests/ListLib.cpp)
target_link_libraries(ListLib linkedList)

enable_testing()
add_test(IteratorTest Iterator)
add_test(RevIterTest RevIterator)
add_test(ConstIterTest ConstIterator)
add_test(ConstRevIterTest ConstRevIterator)
add_test(ListLibTest ConstRevIterator)