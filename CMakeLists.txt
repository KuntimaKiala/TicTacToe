cmake_minimum_required(VERSION 3.0)

project( TicTacToe
         VERSION 0.0.0
         LANGUAGES CXX C

)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Release")


set(ENGINE_TARGET_NAME Engine)
set(GAME_TARGET_NAME Game)

add_subdirectory(Engine)
add_subdirectory(Game)


