cmake_minimum_required(VERSION 3.25)
set(CMAKE_TOOLCHAIN_FILE $ENV{EMSDK}/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake CACHE STRING "Emscripten toolchain file")
project(msdfgen-wasm CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
endif()

add_library(msdfgen-core STATIC IMPORTED)
set_target_properties(msdfgen-core PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/ext/msdfgen/lib/libmsdfgen-core.a)

add_library(msdfgen-ext STATIC IMPORTED)
set_target_properties(msdfgen-ext PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/ext/msdfgen/lib/libmsdfgen-ext.a)

add_library(msdfgen-wasm msdfgenWasm.cpp)
target_include_directories(msdfgen-wasm PRIVATE ext/msdfgen/include)
target_link_libraries(msdfgen-wasm PRIVATE msdfgen-core msdfgen-ext)