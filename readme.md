# CMake Build

`cmake -B ./build -G Ninja`

# Make Build Folder using ninja

`ninja -C ./build`

# install CMake After Build folder is generated

`cmake --install ./build`

# CMake Build With CMAKE_PREFIX_PATH for Find_Package, Find_Library

`cmake -B ./build -G Ninja -DCMAKE_PREFIX_PATH=/usr/local/share/MyLib/cmake`


