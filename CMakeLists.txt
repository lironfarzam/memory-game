cmake_minimum_required(VERSION 3.14)  # Specify the minimum version of CMake

project(MemoryGame)  # Name your project

# Set C++ standard/version using CMAKE_CXX_STANDARD
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable to the project
add_executable(MemoryGame main.cpp Game.cpp Board.cpp Card.cpp HumanPlayer.cpp ComputerPlayer.cpp Utility.cpp Player.cpp CardFactory.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})
