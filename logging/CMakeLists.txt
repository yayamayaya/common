cmake_minimum_required(VERSION 3.5)

file(GLOBAL SRCS src/*)

add_library(logging ${SRCS})

target_include_directories(
    logging
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)