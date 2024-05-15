cmake_minimum_required(VERSION 2.8)

project(crear)

add_executable(${PROJECT_NAME}_db "crear_db.cpp")
target_link_libraries(${PROJECT_NAME}_db sqlite3)