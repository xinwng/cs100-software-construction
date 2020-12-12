#ifndef _perimeter_test_hpp
#define _perimeter_test_hpp

#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

TEST(PerimeterTest, PosNums)
{
    Rectangle test = Rectangle(3, 5);
    EXPECT_EQ(test.perimeter(), 16);
}

TEST(PerimeterTest, Zero)
{
    Rectangle test = Rectangle(0, 0);
    EXPECT_EQ(test.perimeter(), 0);
}

TEST(PerimeterTest, NegNums)
{
    Rectangle test = Rectangle(-5, -5);
    EXPECT_EQ(test.perimeter(), -20);
}

#endif //_perimeter_test_hpp