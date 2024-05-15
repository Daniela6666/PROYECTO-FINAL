cmake_minimum_required(VERSION 2.8)

project(ejecutable)

add_executable(${PROJECT_NAME}_consola main.cpp sensores.h sensores.cpp)
target_link_libraries(${PROJECT_NAME}_consola sqlite3)