#include <gtest/gtest.h>
#include "transformation.hpp"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(transformation(1,1,"am") == "0101");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(transformation(0,0,"am") == "error");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(transformation(12,0,"am") == "1200");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(transformation(-10,-50, "am") == "error");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(transformation(12,0,"agsgm") == "error");
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(transformation(12,15,"pm") == "0015");
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(transformation(14,60,"pm") == "error");
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(transformation(5,40,"pm") == "1740");
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(transformation(5,04,"am") == "0504");
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(transformation(12,9,"pm") == "0009");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}