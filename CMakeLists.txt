cmake_minimum_required(VERSION 3.21)
project(alpha LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(alpha 
    src/main.cpp 
    src/gameObject.cpp
    src/scene.cpp
    src/sceneHandler.cpp
    src/spriteObject.cpp
    # include/placeholder.hpp
)
target_include_directories(alpha PRIVATE "include")
target_include_directories(alpha PRIVATE "assets")
target_link_libraries(alpha PRIVATE sfml-graphics)
