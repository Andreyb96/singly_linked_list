# singly_linked_list
C++ realization of singly linked list

How to build this project (Release):

cmake -B build -DCMAKE_BUILD_TYPE=Release -G"Visual Studio 15 2017" -A x64
cmake --build build -j8 --config Release
cd build
ctest -C Release --output-on-failure