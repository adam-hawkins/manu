cmake_minimum_required(VERSION 3.16)
project(Manu VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_EXTENSIONS OFF)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)
add_executable(Manu ${SRC_FILES})
target_link_libraries(Manu ${CURSES_LIBRARIES})
