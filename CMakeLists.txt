cmake_minimum_required(VERSION 3.20)

project(LearnCpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "/usr/local/share/MyLib/cmake")

find_package(tripleLib REQUIRED)
# add_subdirectory(triple)

add_executable(LearnCpp src/main.cpp)

target_link_libraries(LearnCpp PUBLIC triple)
