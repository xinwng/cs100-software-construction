#ifndef _area_test_hpp_
#define _area_test_hpp_

#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

TEST(AreaTest, PosNums)
{
    Rectangle test = Rectangle(3, 5);
    EXPECT_EQ(test.area(), 15);
}

TEST(AreaTest, Zero)
{
    Rectangle test = Rectangle(0, 0);
    EXPECT_EQ(test.area(), 0);
}

TEST(AreaTest, PosNum_Zero)
{
    Rectangle test = Rectangle(15, 0);
    EXPECT_EQ(test.area(), 0);
}

#endif //_area_test_hpp_