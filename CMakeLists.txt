cmake_minimum_required(VERSION 3.11.0)
project(cargo_management)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    source/alcohol.cpp
    source/cargo.cpp
    source/dryfruit.cpp
    source/fruit.cpp
    source/item.cpp
    source/ship.cpp
    source/weapon.cpp
    )

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} source/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib)