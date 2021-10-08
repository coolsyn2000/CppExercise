cmake_minimum_required(VERSION 3.20)
project(employee_management)

set(CMAKE_CXX_STANDARD 14)

add_executable(employee_management main.cpp header/workerManager.h workManager.cpp header/worker.h header/employee.h employee.cpp header/manager.h manager.cpp header/boss.h boss.cpp)
