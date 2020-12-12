#ifndef __BUBBLE_SORT_TEST_HPP__
#define __BUBBLE_SORT_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/vector_container.hpp"
#include "../header/bubble_sort.hpp"
#include "../header/sort.hpp"
#include "../header/add.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"
#include "../header/div.hpp"
#include "../header/rand.hpp"
#include "../header/sub.hpp"
#include "../header/mult.hpp"

TEST(SortTestSet, BubbleSortTest)
{
    Op *nine = new Op(9);
    Op *two = new Op(2);
    Mult *A = new Mult(nine, two);

    Op *five = new Op(5);
    Op *six = new Op(6);
    Add *B = new Add(five, six);

    Op *eight = new Op(8);
    Op *one = new Op(1);
    Sub *C = new Sub(eight, one);

    vectorContainer *test_container = new vectorContainer();
    test_container->add_element(A);
    test_container->add_element(B);
    test_container->add_element(C);

    ASSERT_EQ(test_container->size(), 3);

    EXPECT_EQ(test_container->at(0)->evaluate(), 18);
    EXPECT_EQ(test_container->at(1)->evaluate(), 11);
    EXPECT_EQ(test_container->at(2)->evaluate(), 7);

    test_container->set_sort_function(new bubbleSort());
    test_container->sort();
    
    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 18);
    EXPECT_EQ(test_container->at(1)->evaluate(), 11);
    EXPECT_EQ(test_container->at(2)->evaluate(), 7);
};



#endif //__BUBBLE_SORT_TEST_HPP__