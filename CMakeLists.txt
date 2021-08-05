cmake_minimum_required(VERSION 3.19)
project(ndt)

set(CMAKE_CXX_STANDARD 17)

set(PYTHON_LIBRARY /usr/lib/python3.8 )
set(PYTHON_INCLUDE_DIR /usr/include/python3.8 )

find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

find_package(PythonInterp 3.8 REQUIRED)
find_package(PythonLibs 3.8 REQUIRED)

add_library(ndt lib/main.cpp include/main.hpp)
target_link_libraries(ndt LINK_PUBLIC  ${Boost_LIBRARIES} ${PythonLibs_LIBRARIES} pthread)

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS} )


