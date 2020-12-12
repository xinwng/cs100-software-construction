#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/pow.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"

TEST(PowTest, PowEvaluate3_5){
    Op* three = new Op(3);
    Op* five = new Op(5);
    Pow* test = new Pow(three, five);
    EXPECT_EQ(test->evaluate(), 243);
}

TEST(PowTest, PowStringify3_5){
    Op* three = new Op(3);
    Op* five = new Op(5);
    Pow* test = new Pow(three, five);
    EXPECT_EQ(test->stringify(), "3 ** 5");
}

TEST(PowTest, PowEvaluate5_0){
    Op* five = new Op(5);
    Op* zero = new Op(0);
    Pow* test = new Pow(five, zero);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowStringify5_0){
    Op *five = new Op(5);
    Op *zero = new Op(0);
    Pow *test = new Pow(five, zero);
    EXPECT_EQ(test->stringify(), "5 ** 0");
}

#endif //__POW_TEST_HPP__
