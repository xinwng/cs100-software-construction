#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "div.hpp"
#include "op.hpp"

TEST(DivTest, DivEvaluate10_5){
    Op* ten = new Op(10);
    Op* five = new Op(5);
    Div* test = new Div(ten, five);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(DivTest, DivStringify10_5){
    Op* ten = new Op(10);
    Op* five = new Op(5);
    Div* test = new Div(ten, five);
    EXPECT_EQ(test->stringify(), "10 / 5");
}

TEST(DivTest, DivEvaluateNeg100_Neg10){
    Op* neg100 = new Op(-100);
    Op* neg10 = new Op(-10);
    Div* test = new Div(neg100, neg10);
    EXPECT_EQ(test->evaluate(), 10);
    
}

TEST(DivTest, DivStringifyNeg100_Neg10){
    Op *neg100 = new Op(-100);
    Op *neg10 = new Op(-10);
    Div *test = new Div(neg100, neg10);
    EXPECT_EQ(test->stringify(), "-100 / -10");
}

#endif //__DIV_TEST_HPP__