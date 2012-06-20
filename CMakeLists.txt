cmake_minimum_required(VERSION 2.6)
project(DCPU16-LIBC)
enable_language(ASM)
enable_language(C)

set(CMAKE_C_COMPILER "clang" CACHE FILEPATH "C Compiler")
set(CMAKE_C_FLAGS "-target dcpu16 -S" CACHE STRING "Global C Flags")
set(CMAKE_ASM_COMPILER "as" CACHE FILEPATH "ASM Compiler")
set(CMAKE_LINKER "ld" CACHE FILEPATH "Static Linker")
set(CMAKE_AR "ar" CACHE FILEPATH "Static Archiver")

include_directories(include)

file(GLOB_RECURSE LIBC_C_SRCS libc/*.c)
file(GLOB_RECURSE LIBC_S_SRCS libc/*.s)
add_library(c ${LIBC_C_SRCS} ${LIBC_S_SRCS})
