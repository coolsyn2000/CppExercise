cmake_minimum_required(VERSION 3.20)
project(SpeechCompetition)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpeechCompetition main.cpp speechManager.h speechManager.cpp speaker.cpp speaker.h)
