cmake_minimum_required(VERSION 3.10)
project(IntersectionSimulation)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(IntersectionSimulation
    main.cpp
    IntersectionManager.cpp
    Car.cpp
)

target_link_libraries(IntersectionSimulation ${SDL2_LIBRARIES})
