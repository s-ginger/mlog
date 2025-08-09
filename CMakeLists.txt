cmake_minimum_required(VERSION 3.10)
project(mlog VERSION 0.1.0 LANGUAGES C)



add_library(mlog STATIC
    src/mlog.c
)

target_include_directories(mlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(example example/main.c)
    target_link_libraries(example PRIVATE mlog)
endif()

