cmake_minimum_required(VERSION 3.14)
project(CGR_MP C)

set(CMAKE_C_STANDARD 11)

include_directories("//usr//local//lib//libgraph-1.0.2//")

build_command("lgraph")

add_executable(CGR_MP main.c)