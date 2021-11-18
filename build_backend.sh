echo "Building SudokuSolverBackend"

cd backend
rm -rf build
mkdir build
cd build
cmake ..
make
cd ../..

echo "Finished building"