cmake_minimum_required(VERSION 3.20)

project(coroutine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(
    HEADER_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/generator.hpp" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/coroutine.hpp"
)

add_library(coroutine INTERFACE ${HEADER_FILES})

target_include_directories(coroutine INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>  # <prefix>/include/mylib
)
