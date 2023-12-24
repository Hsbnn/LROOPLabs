cmake_minimum_required(VERSION 3.8)
#требования к версии

project(fLR7)
#имя проекта

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fLRp7 main.cpp npc.cpp robber.cpp wolf.cpp bear.cpp)
add_executable(fLRt7 tests.cpp npc.cpp robber.cpp wolf.cpp bear.cpp)

enable_testing()
target_link_libraries(fLRp7 Threads::Threads)
target_link_libraries(fLRt7 ${GTEST_LIBRARIES} Threads::Threads)
add_test(NAME BASIC COMMAND fLRt7)
