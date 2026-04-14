cmake_minimum_required(VERSION 3.16)
project(Powerclick)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6.1 COMPONENTS graphics window audio system REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)

