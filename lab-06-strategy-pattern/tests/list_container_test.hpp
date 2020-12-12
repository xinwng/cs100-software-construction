#ifndef __LIST_CONTAINER_TEST_HPP__
#define __LIST_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/container.hpp"
#include "../header/list_container.hpp"
#include "../header/selection_sort.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/mult.hpp"

TEST(ListContainerTestSet, Add4)
{
    Op *four = new Op(4);
    ListContainer *test_container = new ListContainer();
    test_container->add_element(four);
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 4);
}

TEST(ListContainerTestSet, Add4_3)
{
    Op *four = new Op(4);
    Op *three = new Op(3);
    ListContainer *test_container = new ListContainer();
    test_container->add_element(four);
    test_container->add_element(three);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 4);
    EXPECT_EQ(test_container->at(1)->evaluate(), 3);
}

TEST(ListContainerTestSet, Print1)
{
    Op *six = new Op(6);
    Op *eight = new Op(8);
    Add *plus = new Add(six, eight);
    ListContainer *test_container = new ListContainer();
    test_container->add_element(plus);
    string result = "6 + 8";
    ASSERT_EQ(test_container->size(), 1);
    test_container->print();
}

TEST(ListContainerTestSet, Swap2)
{
    // Setup the elements under test
    Op *seven = new Op(7);
    ListContainer *test_container = new ListContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    //otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

#endif //__LIST_CONTAINER_TEST_HPP__