#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "rand.hpp"

TEST(RandTest, RandEvaluateLessThan100) {
    Rand* test = new Rand(5);
    EXPECT_LT(test->evaluate(), 100);
}

#endif //__RAND_TEST_HPP__