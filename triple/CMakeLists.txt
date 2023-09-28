cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/triple.hpp")

add_library(triple INTERFACE ${HEADER_FILES})

target_include_directories(triple INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
