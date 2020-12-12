#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/add.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"

TEST(AddTest, AddEvaluate3_5){
    Op* three = new Op(3);
    Op* five = new Op(5);
    Add* test = new Add(three, five);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(AddTest, AddStringify3_5){
    Op* three = new Op(3);
    Op* five = new Op(5);
    Add* test = new Add(three, five);
    EXPECT_EQ(test->stringify(), "3 + 5");
}

TEST(AddTest, AddEvaluate0_0){
    Op* zero = new Op(0);
    Add* test = new Add(zero, zero);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddStringify0_0){
    Op *zero = new Op(0);
    Add *test = new Add(zero, zero);
    EXPECT_EQ(test->stringify(), "0 + 0");
}

#endif //__ADD_TEST_HPP__                                       
