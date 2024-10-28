cmake_minimum_required(VERSION 3.10)
project("sdl-template" VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
include_directories(libs/sdl/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

add_subdirectory(libs/sdl)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

if(WIN32)
    set(SDL3_LIBRARY "sdl3.dll")
elseif(UNIX)
    set(SDL3_LIBRARY "sdl3.so")
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        "$<TARGET_FILE_DIR:${PROJECT_NAME}>/libs/sdl/${SDL3_LIBRARY}" $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
