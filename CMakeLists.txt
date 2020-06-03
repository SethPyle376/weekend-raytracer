project(WEEKEND_RAYTRACER)

set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.4.1)

include_directories(include)
include_directories(external/stb)

file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SUBSOURCES src/*/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES})

add_executable(Application ${SOURCE_FILES})