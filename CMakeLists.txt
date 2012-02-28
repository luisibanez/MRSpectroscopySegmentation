cmake_minimum_required(VERSION 2.8)

project(MRSpectroscopy)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH})

include(CTest)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  )

add_subdirectory(src)
add_subdirectory(test)
