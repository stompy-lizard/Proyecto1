# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

cmake_minimum_required(VERSION 3.1...3.15)
project(Main)

find_package(CGAL REQUIRED OPTIONAL_COMPONENTS Qt5)

if(CGAL_Qt5_FOUND)
add_definitions(-DCGAL_USE_BASIC_VIEWER -DQT_NO_KEYWORDS)
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


file(GLOB SOURCES_EXE "src/*.cpp")
add_compile_options("-W" "-Wall" "-pedantic")
add_executable(Main ${SOURCES_EXE})

# create a target
# create_single_source_cgal_program("${CMAKE_CURRENT_SOURCE_DIR}/src/Proyecto1.cpp")

if(CGAL_Qt5_FOUND)
  target_link_libraries(Main PUBLIC CGAL::CGAL_Qt5)
endif()
