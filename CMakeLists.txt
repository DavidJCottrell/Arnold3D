cmake_minimum_required(VERSION 3.28)
project(Arnold3D)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)

add_executable(Arnold3D src/main.cpp
        include/Screen.h
        src/Screen.cpp
        include/Cube.h
        src/Cube.cpp
)

target_link_directories(Arnold3D PRIVATE ${SDL2_LIBRARY_DIR})
target_link_libraries(Arnold3D PUBLIC SDL2 SDL2_mixer SDL2_image)
