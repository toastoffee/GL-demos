cmake_minimum_required(VERSION 3.27)

project(GL_demos)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(third_party)

include_directories(${src_dir})
include_directories(${third_party_include_dir})

link_directories(${third_party_link_dir})

file(GLOB src_files ${src_dir}/*.cpp)

message(STATUS "source files:")
foreach (file ${src_files})
    message(STATUS ${file})
endforeach ()

foreach (folder ${third_party_src_dir})
    file(GLOB srcs ${folder}/*.cpp ${folder}/*.c)
    list(APPEND third_party_src_files ${srcs})
endforeach ()

message(STATUS "third-party source files:")
foreach (file ${third_party_src_files})
    message(STATUS ${file})
endforeach ()


add_executable(GL_demos main.cpp
    ${src_files}
    ${third_party_src_files}
        src/tgl_window.hpp)

target_link_libraries(${PROJECT_NAME}
        ${third_party_link_libs})