#include <iostream>
#include <vector>
#include <iostream>
#include <memory>
#include <list>
#include <utility>
#include <map>

#include "allocator.hpp"
#include "Myqueue.hpp"

template <typename T>
void printContainer(const T& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    // Создание экземпляра std::map с созданным аллокатором
    std::map<int, int, std::less<>, MyAllocator<std::pair<const int, int>, 1000>> myMap;

    // Заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; ++i) {
        myMap.emplace(i, factorial(i));
    }

    // Вывод на экран всех значений хранящихся в контейнере
    for (const auto& pair : myMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // Создание экземпляра своего контейнера для хранения int с собственным аллокатором
    MyQueue<int, 1000, MyAllocator<int, 1000>> myQueue;

    // Заполнение контейнера и печать его элементов
    for (int i = 0; i < 10; ++i) {
        myQueue.enqueue(i);
    }
    printContainer(myQueue);

    return 0;
}       
