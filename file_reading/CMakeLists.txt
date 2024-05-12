cmake_minimum_required(VERSION 3.28)

set(SOURCES
    src/file_reading.cpp
)

set(HEADERS
    src/file_reading.h
)

add_library(file_reading ${SOURCES} ${HEADERS})

target_include_directories(
    file_reading
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
