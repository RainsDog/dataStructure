# 查询目录中的源文件
aux_source_directory(. DIRSRCS)

# 定义源文件列表
set(SRC_LIST ${DIRSRCS})

# 生成库文件
add_library(static_seqlist STATIC seqlist.cpp) 
add_library(shared_seqlist SHARED seqlist.cpp) 

# 给动态库添加版本号
SET_TARGET_PROPERTIES(shared_seqlist PROPERTIES VERSION 1.0 SOVERSION 1)

# 改变最终生成的静态库的名字
SET_TARGET_PROPERTIES(static_seqlist PROPERTIES OUTPUT_NAME seqlist)
SET_TARGET_PROPERTIES(shared_seqlist PROPERTIES OUTPUT_NAME seqlist)

# 指定生成库文件的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 指定安装路径
install (TARGETS static_seqlist DESTINATION lib)
install (TARGETS shared_seqlist DESTINATION lib)
install (FILES "${PROJECT_SOURCE_DIR}/list/seqlist/seqlist.h" DESTINATION include)




