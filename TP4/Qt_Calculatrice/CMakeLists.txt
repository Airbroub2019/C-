cmake_minimum_required(VERSION 3.1.0)

project(TP4_3)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()
add_executable(${PROJECT_NAME} "main.cpp" "qt.cc")

target_link_libraries(TP4_3 Qt5::Widgets)
