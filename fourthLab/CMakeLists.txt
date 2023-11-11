cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR4)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20) #стандарт языка си++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(fLRp4 main.cpp figure.hpp point.hpp pentagon.hpp trapezia.hpp romb.hpp Vector.hpp)  
#fLRp - запуск main программы

enable_testing() #указывает CMake, что планируется использование CTest
add_executable(fLRt4 tests.cpp figure.hpp point.hpp pentagon.hpp trapezia.hpp romb.hpp Vector.hpp)
#fLRt - запуск тестов отдельно для функции

target_link_libraries(fLRt4 ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND fLRt4)