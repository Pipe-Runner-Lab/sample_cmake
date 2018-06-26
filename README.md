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

A rather comlex example of make ( where one target can call the other )
> target: dependency1 dependency 2  
command_depending_on_the_dependencies
```
CC=g++

CFLAG=-c -Wall

all: hello

hello: main.o function1.o function2.o
	$(CC) main.o function1.o function2.o -o output

main.o: main.cpp
	$(CC) $(CFLAG) main.cpp

function1.o: function1.cpp
	$(CC) $(CFLAG) function1.cpp

function2.o: function2.cpp
	$(CC) $(CFLAG) function2.cpp

clean:
	rm -rf *.o output
```

**Note:** Only files that have been changed after last compilation will be recompiled.

## Manual compilation
The g++ compiler can be manually invoked to compile the project and to generate the binary like so:
```
g++ ../src/game_engine.cpp ../src/game_interface.cpp ../src/main.cpp -I ../src -I ../include -I ../libs/Logger/include -I ../libs/Randomize/include -L ../libs/Logger -l logger -L ../libs/Randomize -l randomize
```
Here **-I** flag is used to tell the compiler which directories contain the header files.
**-L** flag is used to tell the compiler which directories contain the static library files (.a). **-l** flag is used to specify the name of the complier, which internally is prepended or postpended by the compiler. Hence here the compiler is looking for *liblogger.a* or *loggerlib.a*.

To convert the *.o* file(s) into *.a* file, we use the following command:
```
g++ -c .src/randomize_util.cpp -I ./include
```

Once this has been done, we use the **ar** tool to generate the archieve like so:
```
ar rsv librandomize.a a.o b.o c.o
```