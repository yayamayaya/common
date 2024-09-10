cmake_minimum_required(VERSION 3.15)

set(SOURCES
    src/file_reading.cpp
)

add_library(file_reading src/file_reading.cpp)

target_include_directories(
    file_reading
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
    
target_link_libraries(file_reading logging)