cmake_minimum_required(VERSION 3.23)
project (c_course)

set(CMAKE_CXX_STANDARD 17)

# 添加源文件
add_executable(c_course main.cpp)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()