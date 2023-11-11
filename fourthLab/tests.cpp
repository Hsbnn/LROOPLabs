#include <gtest/gtest.h>
#include "trapezia.hpp"
#include "romb.hpp"
#include "pentagon.hpp"
#include "Vector.hpp"
#include <iostream>

using namespace std;

TEST(Trapezia_, test_TrapeziaInit_01)
{
    Trapezia<int> tr;
    Point<int> p(1,1), p2(2,3), p3(4,3), p6(5,1);
    Point<int> p4(p6);
    Trapezia<int> tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p.x_ == 1);
    ASSERT_TRUE(p2.x_ == 2);
    ASSERT_TRUE(tr == tr2);
}

TEST(Trapezia_, test_TrapeziaInit_02)
{
    Trapezia<int> tr;
    Point<int> p(-1,-1), p2(-2,-3), p3(-4,-3), p6(-5,-1);
    Point<int> p4;
    p4 = p6;
    Trapezia<int> tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p4 == p6);
    ASSERT_TRUE(!(p4 == p2));
    ASSERT_TRUE(tr == tr2);
}

TEST(Trapezia_, test_TrapeziaSquare_01)
{
    Point<double> p(1.0,1.0), p2(2.0,3.0), p3(4.0,3.0), p6(5.0,1.0);
    Point<double> p4(p6);
    Trapezia<double> tr(p,p2,p3,p4);
    ASSERT_TRUE(tr.square() == 6.0);
}

TEST(Trapezia_, test_TrapeziaSquare_02)
{
    Trapezia<int> tr;
    Point<int> p(-1,-1), p2(-2,-3), p3(-4,-3), p6(-5,-1);
    Point<int> p4;
    p4 = p6;
    Trapezia<int> tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(tr.square() == 6);
    cout << "tr.square() 2   " << tr.square() << endl;
}

TEST(Trapezia_, test_TrapeziaCenter_01)
{
    Trapezia<int> tr;
    Point<int> p(-1,-1), p2(-2,-3), p3(-4,-3), p6(-5,-1);
    Point<int> p4;
    p4 = p6;
    Point<int> p10(-3,-2);
    Trapezia<int> tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(tr.center() == p10);

    cout << "tr.center() 1  " << tr.center() << endl;
}

TEST(Trapezia_, test_TrapeziaCenter_02)
{
    Trapezia<int> tr;
    Point<int> p10;
    ASSERT_TRUE(tr.center() == p10);
}

TEST(Romb_, test_RombInit_01)
{
    Trapezia<int> tr;
    Point<int> p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    Point<int> p4;
    p4 = p6;
    Trapezia<int> tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p4 == p6);
    ASSERT_TRUE(!(p4 == p2));
    ASSERT_TRUE(tr == tr2);
}

TEST(Romb_, test_RombInit_02)
{
    Romb<int> tr;
    Point<int> p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    Point<int> p4(p6);
    Romb<int> tr2(p,p2,p3,p4);
    tr = tr2;
    ASSERT_TRUE(p4.x_ == 3);
    ASSERT_TRUE(p4.y_ == -5);
    ASSERT_TRUE(tr == tr2);
}

TEST(Romb_, test_RombSquare_01)
{
    Point<int> p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    Romb<int> tr2(p,p2,p3,p6);
    int sqr = tr2;
    ASSERT_TRUE(sqr == 4);
}

TEST(Romb_, test_RombSquare_02)
{
    Vector<int> arr;
    Point<int> p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5);
    auto tr2 = std::make_unique<Romb<int>>(p,p2,p3,p6);
    arr.push_back(std::move(tr2));

    ASSERT_TRUE(arr.get(0)->square() == 4);

}

TEST(Romb_, test_RombCenter_01)
{
    Vector<int> arr;
    Point<int> p(2,-3), p2(3,-1), p3(4,-3), p6(3,-5),p7(3,-3);
    auto tr2 = std::make_unique<Romb<int>>(p,p2,p3,p6);
     arr.push_back(std::move(tr2));

    ASSERT_TRUE(arr.get(0)->center() == p7);

}


TEST(Romb_, test_RombCenter_02)
{
    Trapezia<float> tr;
    Point<float> p, p2, p3, p6;
    Point<float> p4(p6);
    Trapezia<float> tr2(p,p2,p3,p4);
    ASSERT_TRUE(tr.center() == p);
}

TEST(Pentagon_, test_PentagonInit_01)
{
    Pentagon<int> tr;
    ASSERT_TRUE(tr.square() == 0);
    Point<int> p(2,-3), p2(3,-1), p3(5,-3), p6(4,-4), p7(4,-4);
    Pentagon<int> tr2(p,p2,p3,p6,p7);
    tr = tr2;
    ASSERT_TRUE(tr == tr2);
    ASSERT_TRUE(tr.square() != 0);
}

TEST(Pentagon_, test_PentagonInit_02)
{
    Pentagon<int> tr;
    Point<int> p(2,-3), p2(3,-1), p3(5,-3), p6(4,-4), p7(4,-4);
    Pentagon<int> tr2(p,p2,p3,p6,p7);
    tr = tr2;
    ASSERT_TRUE(p.x_ == 2);
    ASSERT_TRUE(p.y_ == -3);
    ASSERT_TRUE(tr == tr2);
}

TEST(Pentagon_, test_PentagonSquare_01)
{
    Point<float> p(2,-3), p2(3,-1), p3(5,-3), p6(4,-4), p7(4,-4);
    Pentagon<float> tr2(p,p2,p3,p6,p7);
    float sqr = tr2;
    ASSERT_TRUE(sqr != 0);
    std::cout << sqr << std::endl;

}

TEST(Pentagon_, test_PentagonSquare_02)
{
    Vector<int> arr;
    Point<int> p(2,-3), p2(3,-1), p3(5,-3), p6(4,-4), p7(4,-4);
    auto tr2 = std::make_unique<Pentagon<int>>(p,p2,p3,p6,p7);
    arr.push_back(std::move(tr2));

    ASSERT_TRUE(arr.get(0)->square() != 0);

}

TEST(Pentagon_, test_PentagonCenter_01)
{
    Vector<int> arr;
    Point<int> p(2,-3), p2(3,-1), p3(5,-3), p6(4,-4), p7(4,-4);
    auto tr2 = std::make_unique<Pentagon<int>>(p,p2,p3,p6,p7);
    arr.push_back(std::move(tr2));
    Point<int> p10;

    ASSERT_TRUE(!(arr.get(0)->center() == p10));

}

TEST(Pentagon_, test_PentagonCenter_02)
{
    Pentagon<int> tr;
    Point<int> p, p2, p3, p6, p7;
    Pentagon<int> tr2(p,p2,p3,p6,p7);
    ASSERT_TRUE(tr.center() == p);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
