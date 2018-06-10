# sample_cmake
This repo is to understand the working of cmake and make in a C++ project

---

## What is CMake?
It is a build tool that basically takes in the name of the *source file(s)* and *various parameters* mentioned in a file called **CMakeLists.txt** and spits out a **make** file that in turn could be used to create the final executable binary.

### Initial file structure
* CMakeLists.txt (only file required by cmake)
* main.cpp (source file)

### Build process
The usual trend is to create a build directory so as to hold the output of cmake in a seperate directory. Then we point cmake to the location where CMakeLists.txt resides. Then CMake shall spit out several files out of which **make** is the one we are concerned with.
1. mkdir build
2. cd build
3. cmake ..
4. make

