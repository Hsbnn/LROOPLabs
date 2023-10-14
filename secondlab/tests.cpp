#include <gtest/gtest.h>
#include "Three.hpp"

TEST(lessGreatEq, test_01)
{
    Three th1("100"), th("100");
    ASSERT_TRUE( th1 == th );
}

TEST(lessGreatEq, test_00)
{
    Three th1, th;
    ASSERT_TRUE( th1 == th );
}

TEST(lessGreatEq, test_000)
{
    Three th1("10"), th;
    ASSERT_FALSE( th1 == th );
}

TEST(lessGreatEq, test_02)
{
    Three th1("10"), th("201");
    ASSERT_FALSE( th1 == th );
}

TEST(lessGreatEq, test_03)
{
    Three th1("1"), th("1");
    ASSERT_TRUE( th1 == th );
}

TEST(lessGreatEq, test_04)
{
    Three th1("100"), th("10");
    ASSERT_TRUE( th1 > th );
}

TEST(lessGreatEq, test_05)
{
    Three th1("0"), th = {'2','0','0'};
    ASSERT_TRUE( th1 < th );
}

TEST(lessGreatEq, test_06)
{
    Three th1(4,'2'), th(3, '1');
    ASSERT_TRUE( th1 > th );
}

TEST(lessGreatEq, test_07)
{
    Three th1(4, '1'), th("1111");
    ASSERT_TRUE( th1 == th );
}

TEST(lessGreatEq, test_08)
{
    Three th("100");
    Three th1;
    th1 = th;
    ASSERT_TRUE( th1 == th );
}

TEST(lessGreatEq, test_09)
{
    Three th(3, '1');
    Three th1;
    th1 = th;
    ASSERT_TRUE( th1 == th );
}

TEST(lessGreatEq, test_10)
{
    Three th(3, '1');
    Three thh(3, '1');
    Three th1;
    Three t;
    th1 = std::move(th);
    ASSERT_TRUE( th1 == thh );
    ASSERT_TRUE( th == t );
}

TEST(PlusMinus, test_1)
{
    Three th1("0"), th("200");
    Three ths;
    ths = th1 + th;
    ASSERT_TRUE( th1 + th == ths );
}

TEST(PlusMinus, test_2)
{
    Three th1("20"), th("200");
    Three ths("220");
    ASSERT_TRUE( th1 + th == ths );
}

TEST(PlusMinus, test_3)
{
    Three th1("212"), th("0");
    Three ths("212");
    ASSERT_TRUE( th1 + th == ths );
}

TEST(PlusMinus, test_4)
{
    Three th1("222"), th("222");
    Three ths("1221");
    ASSERT_TRUE( th1 + th == ths );
}

TEST(PlusMinus, test_5)
{
    Three th1(4, '1'), th("200");
    Three ths("2011");
    ASSERT_TRUE( th1 + th == ths );
}

TEST(PlusMinus, test_6)
{
    Three th1("200"), th("0");
    Three ths;
    ths = th1 - th;
    ASSERT_TRUE( th1 - th == ths );
}

TEST(PlusMinus, test_7)
{
    Three th1("220"), th("20");
    Three ths("200");
    ASSERT_TRUE( th1 - th == ths );
}

TEST(PlusMinus, test_8)
{
    Three th1("0"), th("0");
    Three ths("0");
    ASSERT_TRUE( th1 - th == ths );
}

TEST(PlusMinus, test_9)
{
    Three th1(4,'2'), th("2011");
    Three ths("211");
    ASSERT_TRUE( th1 - th == ths );
}

TEST(PlusMinus, test_10)
{
    Three th1(4,'2'), th;
    Three ths("2222");
    ASSERT_TRUE( th1 - th == ths );
}

TEST(PlusMinus, test_11)
{
    Three th1(4,'2'), th;
    Three ths("2222");
    ASSERT_TRUE( th1 + th == ths );
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
