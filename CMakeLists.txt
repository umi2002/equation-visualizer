cmake_minimum_required(VERSION 3.10)
project(Test)

if (POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCE_FILES
    #Source files
    src/main.cpp
    src/KeyStates.cpp

    #Header files
    include/KeyStates.hpp
    )

add_executable(Test ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(Test ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
