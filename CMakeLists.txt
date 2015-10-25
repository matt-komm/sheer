cmake_minimum_required (VERSION 2.8)

project (serial)
set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x")

include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_SOURCE_DIR}/external/cereal/include)

add_subdirectory(tests)
add_subdirectory(external)



