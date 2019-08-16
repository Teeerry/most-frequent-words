# 声明要求的cmake最低版本
cmake_minimum_required(VERSION 2.8)

# 声明一个cmake工程
project(Most_Frequent_Words)

# boost 
include_directories( "/usr/include/boost/" )

# 添加一个可执行程序
add_executable(most_frequent_words most_frequent_words.cpp)

