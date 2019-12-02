cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/public)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)