cmake_minimum_required (VERSION 3.22)

project ("engine")

# 三方库
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

# SFML_INCLUDE_DIRS为自定义的目录
file(GLOB SFML_DLL "${SFML_INCLUDE_DIRS}/bin/*")
file(COPY ${SFML_DLL} DESTINATION "${PROJECT_ROOT_NODE}/bin")


# 遍历目录并将路径添加到 include_directories 中  
foreach(INCLUDE_DIR ${LIBRARY_INCLUDES})
  if(IS_DIRECTORY ${INCLUDE_DIR})
    include_directories(${INCLUDE_DIR}/include)  
  endif()
endforeach()

# 指定最终的可执行文件的位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT_NODE}/bin)

# 以当前目录为基准
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# 将源代码添加到此项目的可执行文件。
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

add_executable (${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-window sfml-graphics sfml-audio core)

message(PROJECT:${PROJECT_NAME},G:${CMAKE_C_COMPILER_VERSION},GXX:${CMAKE_CXX_COMPILER_VERSION},CXX STANDARD:${CMAKE_CXX_STANDARD})
message(final)