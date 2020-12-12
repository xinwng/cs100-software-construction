#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/mult.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"

TEST(MultTest, MultEvaluate3_5){
    Op* three = new Op(3);
    Op* five = new Op(5);
    Mult* test = new Mult(three, five);
    EXPECT_EQ(test->evaluate(), 15);
}

TEST(MultTest, MultStringify3_5){
    Op* three = new Op(3);
    Op* five = new Op(5);
    Mult* test = new Mult(three, five);
    EXPECT_EQ(test->stringify(), "3 * 5");
}

TEST(MultTest, MultEvaluate0_0){
    Op* zero = new Op(0);
    Mult* test = new Mult(zero, zero);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringify0_0){
    Op *zero = new Op(0);
    Mult *test = new Mult(zero, zero);
    EXPECT_EQ(test->stringify(), "0 * 0");
}

#endif //__MULT_TEST_HPP__