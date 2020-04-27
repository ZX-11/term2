cmake_minimum_required(VERSION 3.8)

set(PRO_NAME Lab4)

set(CMAKE_C_STANDARD 11)
project(${PRO_NAME})
aux_source_directory(. DIR_SRCS)
add_executable(${PRO_NAME} ${DIR_SRCS})