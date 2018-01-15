# CMake 最低版本要求
cmake_minimum_required (VERSION 2.7)


#项目信息
project (Study_CPPP11)


#包含头文件
include_directories(${PROJECT_SOURCE_DIR}/include)


#工程group显示
file(GLOB_RECURSE INCLUDE_FIELS
         RELATIVE ${PROJECT_SOURCE_DIR}
		 include/*.h)
message("include files: " ${INCLUDE_FIELS})

set(MAIN_DIR src/main)
file(GLOB_RECURSE MAIN_FILES
         RELATIVE ${PROJECT_SOURCE_DIR}
         ${MAIN_DIR}/*.cpp
		 ${MAIN_DIR}/*.c
		 ${MAIN_DIR}/*.h)
		 
set(AUTO_DIR src/auto)
file(GLOB_RECURSE AUTO_FILES
         RELATIVE ${PROJECT_SOURCE_DIR}
         ${AUTO_DIR}/*.cpp
		 ${AUTO_DIR}/*.c
		 ${AUTO_DIR}/*.h)
message("auto files: " ${CURRENT_AUTO_FILES})

source_group("include" FILES ${INCLUDE_FIELS})
source_group("src\\main" FILES ${MAIN_FILES})
source_group("src\\auto" FILES ${AUTO_FILES})

set(ALL_FILES ${INCLUDE_FIELS}
              ${MAIN_FILES}
			  ${AUTO_FILES})

#指定生成目标
add_executable(StudyCPP11 ${ALL_FILES})