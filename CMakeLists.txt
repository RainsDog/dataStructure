# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目工程名
project (demo)

# 项目版本号
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

# 指定头文件包含路径
#include_directories(${PROJECT_SOURCE_DIR}/list/seqList)
#include_directories(${PROJECT_SOURCE_DIR}/list/singleLinkList)
#include_directories(${PROJECT_SOURCE_DIR}/list/staticLinkList)
#include_directories(${PROJECT_SOURCE_DIR}/list/doubleLinkList)
#include_directories(${PROJECT_SOURCE_DIR}/list/circleLinkList)
include_directories(${PROJECT_SOURCE_DIR}/list/seqStack)

# 指定库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/build/lib)

# 指定安装目录
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

# 添加子目录
#add_subdirectory(list/seqList)
#add_subdirectory(list/singleLinkList)
#add_subdirectory(list/staticLinkList)
#add_subdirectory(list/doubleLinkList)
#add_subdirectory(list/circleLinkList)
add_subdirectory(list/seqStack)

add_subdirectory(main)


# 信息输出
#message("env = $ENV{HOME}")
