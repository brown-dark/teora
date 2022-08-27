#-------------------------------------------------------------------#
# cmake version

cmake_minimum_required(VERSION 3.20)

#-------------------------------------------------------------------#
# project flags config

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(TEORA_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEORA_BUILD_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE})

if(WIN32)
    set(MSVC_TOOLSET_VERSION 143)
endif()

#-------------------------------------------------------------------#
# project config

project(teora)

#-------------------------------------------------------------------#
# find build libraries & suplementary functions

include(${CMAKE_CURRENT_SOURCE_DIR}/build_tools/cmake/find_qt6_libs.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/build_tools/cmake/suplementary_functions.cmake)

#-------------------------------------------------------------------#
# configure build folder

CreateBuildDirectory(${TEORA_BUILD_DIR})

#-------------------------------------------------------------------#
# project tree

add_subdirectory(source)

#-------------------------------------------------------------------#