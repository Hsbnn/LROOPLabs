cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR5)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 17) #стандарт языка си++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(fLRp5 main.cpp allocator.hpp Myqueue.hpp)  
#fLRp - запуск main программы

enable_testing() #указывает CMake, что планируется использование CTest
add_executable(fLRt5 tests.cpp allocator.hpp Myqueue.hpp)
#fLRt - запуск тестов отдельно для функции

target_link_libraries(fLRt5 ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND fLRt5)