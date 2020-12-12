#ifndef __SELECTION_SORT_TEST_HPP__
#define __SELECTION_SORT_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/vector_container.hpp"
#include "../header/selection_sort.hpp"
#include "../header/sort.hpp"
#include "../header/add.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"
#include "../header/div.hpp"
#include "../header/rand.hpp"
#include "../header/sub.hpp"
#include "../header/mult.hpp"

TEST(SortTestSet, SelectionSortTest)
{
    Op *seven = new Op(7);
    Op *four = new Op(4);
    Mult *TreeA = new Mult(seven, four);

    Op *three = new Op(3);
    Op *two = new Op(2);
    Add *TreeB = new Add(three, two);

    Op *ten = new Op(10);
    Op *six = new Op(6);
    Sub *TreeC = new Sub(ten, six);

    vectorContainer *container = new vectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new selectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
};

#endif //__BUBBLE_SORT_TEST_HPP__