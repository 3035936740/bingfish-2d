﻿# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.22)

set(PROJECT_ROOT_NODE ${CMAKE_CURRENT_SOURCE_DIR})

# 将指定目录文件所有复制到二进制文件目录
file(GLOB allCopyFiles  "${CMAKE_CURRENT_SOURCE_DIR}/resource/*")
file(COPY ${allCopyFiles} DESTINATION ${PROJECT_ROOT_NODE}/bin)

project ("EngineBingX2d")

file(GLOB LIBRARY_INCLUDES "${PROJECT_ROOT_NODE}/library/*")

# 包含子项目。
add_subdirectory(library)
add_subdirectory(engine)