# CMake 最低版本要求
cmake_minimum_required (VERSION 2.7)


#项目信息
project (Study_CPPP11)


#包含头文件
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/auto)


#工程group显示
file(GLOB_RECURSE INCLUDE_FIELS
         RELATIVE ${PROJECT_SOURCE_DIR}
		 include/*.h)
message("include files: " ${INCLUDE_FIELS})

set(AUTO_DIR src/auto)
file(GLOB_RECURSE CURRENT_AUTO_FILES
         RELATIVE ${PROJECT_SOURCE_DIR}
         ${AUTO_DIR}/*.cpp
		 ${AUTO_DIR}/*.c
		 ${AUTO_DIR}/*.h)
message("auto files: " ${CURRENT_AUTO_FILES})

source_group("include" FILES ${INCLUDE_FIELS})
source_group("src" FILES ${SRCS})
source_group("src\\auto" FILES ${CURRENT_AUTO_FILES})

set(ALL_FILES ${INCLUDE_FIELS}
              ${SRCS}
			  ${CURRENT_AUTO_FILES})

#指定生成目标
add_executable(StudyCPP11 ${ALL_FILES})