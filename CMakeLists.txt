# CMake 最低版本要求
cmake_minimum_required (VERSION 2.7)


#项目信息
project (Study_CPPP11)

#包含头文件
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/auto)


aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/auto DIR_SRCS)

#指定生成目标
add_executable(StudyCPP11 ${DIR_SRCS})