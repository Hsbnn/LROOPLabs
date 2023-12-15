cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR6)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20) #стандарт языка си++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(fLRp6 main.cpp npc.hpp robber.hpp wolf.hpp bear.hpp npc.cpp robber.cpp wolf.cpp bear.cpp)  
#fLRp - запуск main программы

enable_testing() #указывает CMake, что планируется использование CTest
add_executable(fLRt6 tests.cpp npc.hpp robber.hpp wolf.hpp bear.hpp npc.cpp robber.cpp wolf.cpp bear.cpp)
#fLRt - запуск тестов отдельно для функции

target_link_libraries(fLRt6 ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND fLRt6)