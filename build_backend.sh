echo "Building SudokuSolverBackend"

# Should check for a specific version of protobuf
if brew ls --versions protobuf > /dev/null; then
    echo "Protobuf already installed"
else
    echo "Protobuf not installed. Will install now"
    brew install protobuf
fi

#echo "Generating C++ code from protocol"
rm -rf backend/generated
mkdir backend/generated
protoc --proto_path=proto --cpp_out=backend/generated proto/sudoku_solver.proto

echo "Building"
cd backend
rm -rf build
mkdir build
cd build
cmake ..
make
cd ../..

echo "Finished building"