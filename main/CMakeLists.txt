# 查询目录中的源文件
aux_source_directory(. DIRSRCS)

# 定义源文件列表
set(SRC_LIST ${DIRSRCS})

# 指定生成可执行文件目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 指定生成目标 目标名字随便写；${SRC_LIST}代表前面定义的源文件列表变量
add_executable(demo ${SRC_LIST})
#target_link_libraries(demo libseqlist.a)
#target_link_libraries(demo liblinklist.a)
target_link_libraries(demo libseqStack.a)

# 指定安装路径
install (TARGETS demo DESTINATION bin)

# 信息输出
#message("${PROJECT_SOURCE_DIR}/list/seqList/seqlist.h")