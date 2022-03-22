cmake_minimum_required (VERSION 3.0.0)
project (Digging-Simulator CXX)

find_package (SQLite3)
include_directories(${SQLite3_INCLUDE_DIRS})

add_subdirectory(include/fmt EXCLUDE_FROM_ALL)
add_executable(digging src/application.cpp src/engine.h src/init.cpp src/dig.cpp src/sell.cpp src/menu.cpp src/buy.cpp)
target_link_libraries(digging PRIVATE fmt::fmt-header-only)

add_executable(test src/test.cpp)
target_link_libraries (test fmt::fmt)