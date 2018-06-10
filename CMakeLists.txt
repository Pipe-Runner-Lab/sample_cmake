# minimum required version of the cmake tool
cmake_minimum_required( VERSION 3.0 )

# set addition cmake variable according to project need
set( CMAKE_BUILD_TYPE debug )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FALGS} -std=c++14" )

# output - executable name followed by all the source files we wish to compile
add_executable(
	output
	main.cpp
)