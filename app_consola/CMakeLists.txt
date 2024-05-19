cmake_minimum_required(VERSION 2.8)

project(ejecutable)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}_consola ${SOURCES})

target_link_libraries(${PROJECT_NAME}_consola sqlite3)
