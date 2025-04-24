# output
#message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
#message(STATUS "git_test:CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# sys set
cmake_minimum_required(VERSION 3.28.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# pro set
project(wndeda)

# my var 设置动态库和exe输出路径，会传递到子cmake
set(APPSRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/app)
# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 设置共享库输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# 设置静态库输出目录（如果有静态库的话）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)



add_subdirectory(src)








