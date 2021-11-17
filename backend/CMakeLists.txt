cmake_minimum_required(VERSION 3.1)

file(GLOB headers  "*.h")
file(GLOB sources  "*.cc")
file(GLOB headers2 "*/*.h")
file(GLOB sources2 "*/*.cc")
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

add_executable(sudoku_solver_backend ${headers} ${sources} ${headers2} ${sources2})