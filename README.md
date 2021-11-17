# Sudoku Solver

Basic server application that receives Sudoku's as input and generates Sudoku solutions

## Technical design

* Single-threaded event loop that listens to incoming requests
* Define protocol for client to send requests to server
** Request: Unsolved sudoku
** Response: Solved sudoku or Error (if invalid or cannot be solved)

## Technologies used

* C++
* Protobuf
* CMake
* Shell scripting (for builds)



