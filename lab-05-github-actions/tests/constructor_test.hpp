#ifndef _constructor_test_hpp_
#define _constructor_test_hpp_

#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

TEST(ConstructorTest, WidthTest)
{
    int height = 10;
    int width = 5;
    Rectangle test(width, height);
    int result = test.area();
    result = result / height;
    EXPECT_EQ(5, result);
}

TEST(ConstructorTest, HeightTest)
{
    int height = 10;
    int width = 5;
    Rectangle test(width, height);
    int result = test.area();
    result = result / width;
    EXPECT_EQ(10, result);
}

TEST(ConstructorTest, WidthTest2)
{
    int height = 100;
    int width = 20;
    Rectangle test(width, height);
    int result = test.area();
    result = result / height;
    EXPECT_EQ(20, result);
}

#endif //_constructor_test_hpp_