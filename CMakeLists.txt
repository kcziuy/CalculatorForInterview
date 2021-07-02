cmake_minimum_required(VERSION 0.1)

project(Calculator LANGUAGES CXX)

file(GLOB HEADERS   "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB SOURCES   "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Calculator
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
