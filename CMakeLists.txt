cmake_minimum_required(VERSION 3.10)

# cmake options
set (CMAKE_CXX_STANDARD 11)

project(caxeiro)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

# libs opengl to linker
set (CMAKE_CXX_FLAGS "-lGL -lglut")

file(GLOB SOURCES "src/*.cpp")
 
add_executable(caxeiro_viajante ${SOURCES})

