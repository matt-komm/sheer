cmake_minimum_required (VERSION 2.8)

project (serial)
set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x")

include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_SOURCE_DIR}/external/cereal/include)

macro(copy_file_if_changed in_file out_file target)  
        add_custom_target(${target})
    	add_custom_command (
    		TARGET     ${target}
    		POST_BUILD
    		COMMAND    ${CMAKE_COMMAND}
    		ARGS       -E copy_if_different ${in_file} ${out_file}
    		COMMENT "Copying file: ${in_file} to: ${out_file}"
    	)
endmacro(copy_file_if_changed)

add_library(sheer
    src/Float16Converter.cpp
    src/ShortString.cpp
)

add_subdirectory(tests)
add_subdirectory(external)
add_subdirectory(scripts)



