cmake_minimum_required (VERSION 3.22)

project ("engine")

# ������
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

# SFML_INCLUDE_DIRSΪ�Զ����Ŀ¼
file(GLOB SFML_DLL "${SFML_INCLUDE_DIRS}/bin/*")
file(COPY ${SFML_DLL} DESTINATION "${PROJECT_ROOT_NODE}/bin")


# ����Ŀ¼����·�����ӵ� include_directories ��  
foreach(INCLUDE_DIR ${LIBRARY_INCLUDES})
  if(IS_DIRECTORY ${INCLUDE_DIR})
    include_directories(${INCLUDE_DIR}/include)  
  endif()
endforeach()

# ָ�����յĿ�ִ���ļ���λ��
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT_NODE}/bin)

# �Ե�ǰĿ¼Ϊ��׼
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# ��Դ�������ӵ�����Ŀ�Ŀ�ִ���ļ���
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

add_executable (${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-window sfml-graphics sfml-audio core)

message(PROJECT:${PROJECT_NAME},G:${CMAKE_C_COMPILER_VERSION},GXX:${CMAKE_CXX_COMPILER_VERSION},CXX STANDARD:${CMAKE_CXX_STANDARD})
message(final)