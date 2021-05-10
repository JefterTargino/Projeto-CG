cmake_minimum_required(VERSION 3.10)
project(caxeiro)
set (CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)
set (CMAKE_CXX_FLAGS "-lGL -lglut -lGLU")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
file(GLOB SOURCES "src/*.cpp")

add_executable(caxe ${SOURCES})
