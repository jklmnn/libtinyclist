cmake_minimum_required(VERSION 2.6)
project(tinyclist)

set (VERSION_MAJ 0)
set (VERSION_MIN 1)
set (VERSION_FIX 0)
set (AUTHOR Johannes Kliemann)
set (HOMEPAGE https://github.com/jklmnn/libtinyclist)
set (LICENSE MIT)

set (GCC_STRICT_WARNINGS "-Wall -Wextra -Wfloat-equal -Wundef \
-Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 \
-Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
-Wconversion -Wunreachable-code -Winit-self -Wuninitialized -Werror")

include_directories("include")

add_library(tinyclist SHARED src/list.c)
set_target_properties(tinyclist PROPERTIES
    COMPILE_FLAGS ${GCC_STRICT_WARNINGS}
    VERSION ${VERSION_MAJ}.${VERSION_MIN}.${VERSION_FIX}
    SOVERSION 1
    PUBLIC_HEADER src/list.h)

add_executable(test_list test/main.c)
set_target_properties(test_list PROPERTIES
    COMPILE_FLAGS ${GCC_STRICT_WARNINGS})
target_link_libraries(test_list tinyclist)

include(CTest)
enable_testing()

add_test(test test_list)
