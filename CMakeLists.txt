cmake_minimum_required(VERSION 3.24)

project(DanmakuDojo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP FALSE
)
FetchContent_MakeAvailable(raylib)

add_executable(DanmakuDojo src/main.cpp src/Game.cpp src/Player.cpp)
target_link_libraries(DanmakuDojo PRIVATE raylib)

if(MSVC)
    target_compile_options(DanmakuDojo PRIVATE /W4)
else()
    target_compile_options(DanmakuDojo PRIVATE -Wall -Wextra -Wpedantic)
endif()

set_property(TARGET DanmakuDojo PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:DanmakuDojo>")
