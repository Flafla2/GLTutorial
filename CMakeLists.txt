cmake_minimum_required(VERSION 3.1)
project (GLTutorial)

# Cmake Configuration #

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

# OpenGL Configuration #

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# GLFW Configuration #

if( APPLE )
  # Set deploy target to macOS 10.8 to supress deprecation
  # warnings
  set(CMAKE_OSX_DEPLOYMENT_TARGET "10.8")
endif()

# Includes #

include_directories(${OPENGL_INCLUDE_DIR})

add_subdirectory(glfw)

add_subdirectory(src)
