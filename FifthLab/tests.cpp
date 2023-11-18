#include <gtest/gtest.h>
#include <iostream>
#include "Myqueue.hpp"
#include "allocator.hpp"

TEST(MyQueue_Test, test_01)
{
    MyQueue<int, 10, MyAllocator<int, 10>> myQueue;
    for (int i = 0; i < 10; ++i) {
        myQueue.enqueue(i);
    }
    ASSERT_TRUE(  myQueue.size() == 10);
}

TEST(MyQueue_Test, test_02)
{
    MyQueue<int, 10, MyAllocator<int, 10>> myQueue;
    for (int i = 1; i < 11; ++i) {
        myQueue.enqueue(i);
    }
    myQueue.dequeue();
    ASSERT_TRUE( myQueue.size() == 9);

}
TEST(MyQueue_Test, test_02_1)
{
    MyQueue<int, 10, MyAllocator<int, 10>> myQueue;
    for (int i = 1; i < 11; ++i) {
        myQueue.enqueue(i);
    }
    myQueue.dequeue();
    ASSERT_TRUE( myQueue.front() == 2);

}


TEST(MyQueue_Test, test_03)
{
    MyQueue<int, 10, MyAllocator<int, 10>> myQueue;
    for (int i = 0; i < 10; ++i) {
        myQueue.enqueue(i);
    }
    myQueue.empty();
    ASSERT_FALSE(myQueue.empty());
}

TEST(MyQueue_Test, test_04)
{
    MyQueue<int, 10, MyAllocator<int, 10>> myQueue;
    for (int i = 0; i < 10; ++i) {
        myQueue.enqueue(i);
    }
    myQueue.enqueue(500);
    ASSERT_TRUE( myQueue.size() == 11);
}

TEST(MyQueue_Test_iterator, test_01)
{
    MyQueue<int, 10, MyAllocator<int, 10>> queue;
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
    }
    int j = 0;

    for (MyQueue<int, 10, MyAllocator<int, 10>>::iterator it = queue.begin(); it != queue.end(); ++it) {
        ASSERT_TRUE(*it == j);
        ++j;
    }

}

TEST(MyQueue_Test_iterator, test_02)
{
    MyQueue<int, 10, MyAllocator<int, 10>> queue;
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
    }
    int j = 0;
    MyQueue<int, 10, MyAllocator<int, 10>>::iterator it = queue.begin();
    ASSERT_TRUE(*it == 0);

    it = ++(++(++it));

    ASSERT_TRUE(*it == 3);
}

TEST(MyQueue_Test_iterator, test_03)
{
    MyQueue<int, 10, MyAllocator<int, 10>> queue;
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
    }
    int j = 0;
    MyQueue<int, 10, MyAllocator<int, 10>>::iterator it = queue.begin();
    it = ++it;
    ASSERT_TRUE(*(it) == 1);
}

TEST(MyQueue_Test_iterator, test_04)
{
    MyQueue<int, 10, MyAllocator<int, 10>> queue;
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
    }
    int j = 0;

    MyQueue<int, 10, MyAllocator<int, 10>>::iterator it = queue.begin();
    ASSERT_FALSE(*it != 0);

}

TEST(MyQueue_Test_All, test_01)
{
    std::map<int, int, std::less<>, MyAllocator<std::pair<const int, int>, 1000>> myMap;

    MyQueue<int, 100, MyAllocator<int, 100>> queue;
    for (int i = 0; i < 100; ++i) {
        queue.enqueue(i);
    }

    MyQueue<int, 100, MyAllocator<int, 100>>::iterator it = queue.begin();

    for (int i = 0; i < 10; ++i) {
        myMap.emplace(i, *it);
        ASSERT_TRUE(*it == i);
        ASSERT_TRUE(myMap[i] == *it);
        ++it;
    }
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}