rm -rf build install

cmake -S . -B build -DCMAKE_INSTALL_PREFIX=install -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j4 --target install