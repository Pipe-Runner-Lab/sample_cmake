cmake_minimum_required( VERSION 3.0 )

project( sample_cmake )

# flags

# include files
include_directories( ./include ./src ./libs/Logger/include ./libs/Randomize/include )

# target
add_executable( binary ./src/main.cpp ./src/game_engine.cpp ./src/game_interface.cpp )

# 3rd party libs
add_subdirectory( ./libs/Logger )
target_link_libraries( binary logger )

add_subdirectory( ./libs/Randomize )
target_link_libraries( binary randomize )