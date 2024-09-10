cmake_minimum_required(VERSION 3.11.0)
project(cargo_management)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    alcohol.cpp
    cargo.cpp
    dryfruit.cpp
    fruit.cpp
    item.cpp
    ship.cpp
    weapon.cpp
    )

add_library(${PROJECT_NAME}-lib STATIC ${SRC})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}-lib)