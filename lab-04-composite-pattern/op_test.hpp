#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(39);
    EXPECT_EQ(test->stringify(), "39");
}

TEST(OpTest, OpEvaluationZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0");
}

TEST(OpTest, OpEvaluationNegNum) {
    Op* test = new Op(-3);
    EXPECT_EQ(test->evaluate(), -3);
}

TEST(OpTest, OpStringifyNegNum){
    Op* test = new Op(-29);
    EXPECT_EQ(test->stringify(), "-29");
}
#endif //__OP_TEST_HPP__
