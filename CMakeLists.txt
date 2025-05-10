cmake_minimum_required(VERSION 3.10)  # 设置CMake最低版本
project(MyProject)                    # 项目名称（可指定语言，如CXX）

# 正确启用 C99 语言标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)