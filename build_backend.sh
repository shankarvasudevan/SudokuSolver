echo "Building SudokuSolverBackend"

rm -rf backend/build
mkdir backend/build
cd backend/build
cmake ..
make
cd ../..

echo "Finished building"