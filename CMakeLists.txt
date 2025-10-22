cmake_minimum_required(VERSION 3.10)
project(SilentHillDemo)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)

include_directories(include)
add_executable(SilentHillDemo 
    src/main.cpp 
    src/Player.cpp
    src/Game.cpp
    src/Window.cpp
)

target_link_libraries(SilentHillDemo 
    ${OPENGL_LIBRARIES}
    opengl32
    glu32
    gdi32
)