project(WEEKEND_RAYTRACER)

set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.4.1)

include_directories(include)

file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SHAPESOURCES src/shape/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SHAPESOURCES})

add_executable(Application ${SOURCE_FILES})