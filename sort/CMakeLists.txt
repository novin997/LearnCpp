cmake_minimum_required(VERSION 3.20)

project(sort VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(
  HEADER_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/include/sort.hpp"
)

# Include(FetchContent)

# FetchContent_Declare(
# Catch2
# GIT_REPOSITORY https://github.com/catchorg/Catch2.git
# GIT_TAG v3.5.2 # or a later release
# )

# FetchContent_MakeAvailable(Catch2)
add_library(sort INTERFACE ${HEADER_FILES})

target_include_directories(sort INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include> # <prefix>/include/mylib
)

add_executable(unit_tests
  src/main.cpp
)

target_link_libraries(unit_tests PUBLIC sort)
