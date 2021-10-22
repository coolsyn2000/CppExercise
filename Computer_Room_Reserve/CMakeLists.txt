cmake_minimum_required(VERSION 3.20)
project(Computer_Room_Reserve)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(Computer_Room_Reserve main.cpp student.cpp student.h Identity.h teacher.cpp teacher.h Admin.cpp Admin.h globalFile.h computerRoom.h orderFile.cpp orderFile.h)
