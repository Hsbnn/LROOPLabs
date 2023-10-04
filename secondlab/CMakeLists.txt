cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR2)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 17) #стандарт языка си++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(fLRp2 main.cpp Three.cpp)  #fLRp - запуск main программы
enable_testing() #указывает CMake, что планируется использование CTest
add_executable(fLRt2 tests.cpp Three.cpp) 
#fLRt - запуск тестов отдельно для функции

target_link_libraries(fLRt2 ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND fLRt2)