cmake_minimum_required(VERSION 3.20)

project(format VERSION 1.0.0 LANGUAGES CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 23)

set(
    HEADER_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/format.hpp" 
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_library(format INTERFACE ${HEADER_FILES})

target_include_directories(format INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>  # <prefix>/include/mylib
)

add_executable(unit_tests
	test/main.cpp
)

target_link_libraries(unit_tests PUBLIC format Catch2::Catch2WithMain)
