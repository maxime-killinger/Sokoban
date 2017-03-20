cmake_minimum_required(VERSION 3.6)
project(Sokoban)

set(CMAKE_CXX_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(
        ${CURSES_INCLUDE_DIR}
        include/)

set(SOURCE_FILES
        include/my_sokoban.h
        src/check_map.c
        src/color.c
        src/key.c
        src/key_down.c
        src/key_left.c
        src/key_right.c
        src/key_space.c
        src/key_up.c
        src/main.c
        src/my_str_to_wordtab.c
        src/take_map.c)

add_executable(Sokoban ${SOURCE_FILES})
target_link_libraries(Sokoban ${CURSES_LIBRARIES})
