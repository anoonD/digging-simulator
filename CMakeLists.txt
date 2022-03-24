cmake_minimum_required (VERSION 3.0.0)
project (Digging-Simulator CXX)

add_subdirectory(include/fmtlib EXCLUDE_FROM_ALL)

add_executable(digging src/application.cpp  src/engine.cpp src/engine.h src/dig.cpp src/sell.cpp src/menu.cpp src/shop.cpp)
target_link_libraries(digging PRIVATE fmt::fmt-header-only)
