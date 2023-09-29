cmake_minimum_required(VERSION 3.20)

project(tripleLib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/triple.hpp")

add_library(triple INTERFACE ${HEADER_FILES})

target_include_directories(triple INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>  # <prefix>/include/mylib
)

# target_include_directories(triple INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

include(GNUInstallDirs)

# set_target_properties(
#     ${PROJECT_NAME} PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION 1
# )

install(
    TARGETS triple EXPORT tripleLibConfig
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT tripleLibConfig DESTINATION share/MyLib/cmake)

export(TARGETS triple FILE tripleLibConfig.cmake)
