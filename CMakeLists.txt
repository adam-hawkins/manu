cmake_minimum_required(VERSION 3.16)
project(Manu VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_EXTENSIONS OFF)
set(SRC_FILES src/main.c src/c/c.c src/go/go.c src/kotlin/kotlin.c src/python/python.c)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)
#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/c/c.c)
#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/kotlin/kotlin.c)
#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/python/python.c)
#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/go/go.c)
#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.c)

add_executable(Manu ${SRC_FILES})
target_link_libraries(Manu ${CURSES_LIBRARIES})
