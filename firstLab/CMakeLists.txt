cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 17) #стандарт языка си++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(fLRp main.cpp transformation.cpp)  #fLRp - запуск main программы
enable_testing() #указывает CMake, что планируется использование CTest
add_executable(fLRt tests.cpp transformation.cpp) 
#fLRt - запуск тестов отдельно для функции

target_link_libraries(fLRt ${GTEST_LIBRARIES})
#"подключение" библиотек теста
add_test(NAME BASIC COMMAND fLRt)
#регистрирует исполняемый файл, собираемый в проекте как один из тестов для запуска