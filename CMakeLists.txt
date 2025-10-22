cmake_minimum_required(VERSION 3.10)
project(SilentHillDemo)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(include)
add_executable(SilentHillDemo 
    src/main.cpp 
    src/Game.cpp
    src/Player.cpp
)

target_link_libraries(SilentHillDemo 
    ${OPENGL_LIBRARIES} 
    ${GLUT_LIBRARY}
)
