#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "sub.hpp"
#include "base.hpp"
#include "op.hpp"

TEST(SubTest, SubEvaluate5_3){
    Op* five = new Op(5);
    Op* three = new Op(3);
    Sub* test = new Sub(five, three);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(SubTest, SubStringify5_3){
    Op* five = new Op(5);
    Op* three = new Op(3);
    Sub* test = new Sub(five, three);
    EXPECT_EQ(test->stringify(), "5 - 3");
}

TEST(SubTest, SubEvaluate0_0){
    Op* zero = new Op(0);
    Sub* test = new Sub(zero, zero);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubStringify0_0){
    Op *zero = new Op(0);
    Sub *test = new Sub(zero, zero);
    EXPECT_EQ(test->stringify(), "0 - 0");
}

#endif //__SUB_TEST_HPP__                                         
