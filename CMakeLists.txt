cmake_minimum_required(VERSION 3.25)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_MAKE_PROGRAM /usr/bin/make)
project(msdfgen-wasm)

set(MSDFGEN_BUILD_STANDALONE OFF)
find_package(msdfgen REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE msdfgen::msdfgen)