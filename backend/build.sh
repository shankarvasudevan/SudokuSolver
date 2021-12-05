echo "*** Building SudokuSolverBackend ***"

echo "*** Removing previous build artifacts ***"
rm -rf build
mkdir build

echo "*** Running CMake ***"
cmake -S . -B build

echo "*** Building ***"
make -C build

echo "*** Finished building ***"