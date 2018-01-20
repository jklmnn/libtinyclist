cmake_minimum_required(VERSION 2.6)
project(tinyclist)

set (VERSION_MAJ 0)
set (VERSION_MIN 1)
set (VERSION_FIX 0)
set (AUTHOR Johannes Kliemann)
set (HOMEPAGE https://github.com/jklmnn/libtinyclist)
set (LICENSE MIT)

include_directories("${PROJECT_BINARY_DIR}")

add_library(tinyclist SHARED src/list.c)
set_target_properties(tinyclist PROPERTIES
    VERSION ${VERSION_MAJ}.${VERSION_MIN}.${VERSION_FIX}
    SOVERSION 1
    PUBLIC_HEADER src/list.h)
