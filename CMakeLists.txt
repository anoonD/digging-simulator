cmake_minimum_required (VERSION 3.0.0)
project (Digging-Simulator CXX)

find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})
find_package(fmt)

add_executable(digging src/application.cpp src/engine.h src/init.cpp src/dig.cpp src/sell.cpp src/menu.cpp)

add_executable(test src/test.cpp)
target_link_libraries (digging fmt::fmt)

target_link_libraries (test ${SQLite3_LIBRARIES} fmt::fmt)