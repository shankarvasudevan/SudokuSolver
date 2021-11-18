cmake_minimum_required(VERSION 3.1)

file(GLOB headers  "*.h")
file(GLOB sources  "*.cc")
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRC PROTO_HEADERS ../proto/sudoku_solver.proto)

add_executable(sudoku_solver_backend ${PROTO_SRC} ${PROTO_HEADERS} ${headers} ${sources})
target_link_libraries(sudoku_solver_backend ${Protobuf_LIBRARIES})