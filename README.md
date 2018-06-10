# sample_cmake
This repo is to understand the working of cmake and make in a C++ project

---

## What is CMake?
It is a build tool that basically takes in the name of the **source file(s)** and **various parameters** mentioned in a file called **CMakeLists.txt** and spits out a **make** file that in turn could be used to create the final executable binary.

### Initial file structure
* CMakeLists.txt (only file required by cmake)
* main.cpp (source file)

### Build process
The usual trend is to create a build directory so as to hold the output of cmake in a seperate directory. Then we point cmake to the location where CMakeLists.txt resides. Then CMake shall spit out several files out of which **make** is the one we are concerned with. Once cmake has generated the files, there is no need to run cmake again in case any changes are made to CMakeLists.txt; make will know about these changes automatically.
1. mkdir build
2. cd build
3. cmake ..
4. make ( or **make VERBOSE=1** to see under the hood )
  
> *This shall generate the binary executable in the build directory that can be run to verify that the make file indeed compiles the project*  

**Note:** Clean the build directory and try the above commands  

### Final file structure
* CMakeLists.txt (only file required by cmake)
* main.cpp (source file)
* build/
	* CMakeFiles/
	* cmake_install.cmake
	* CMakeCache.txt
	* Makefile
	* output

---

## What is Make?
The main task of Make is to speed up the build process when we have to compile many files at ones. CMake after execution generates a make file. A make file is nothing but a file holding raw commands that need to be executed in order to build the binary.
There can be multiple targets in a make file, but by default, it will execute the first one.

**Note:** Writing **Makefile** is a tedious process, hence **CMake** is a utility to automate that task.

### Structure of a make file
A **Makefile** will have the following structe:
```
target_name_1:
	g++ a.cpp b.cpp c.cpp -o output
target_name_2:
	gcc a.cpp b.cpp -o output
```
To execute a particular target:
> make target_name
