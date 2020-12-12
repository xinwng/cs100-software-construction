#ifndef __VECTOR_CONTAINER_TEST_HPP__
#define __VECTOR_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/container.hpp"
#include "../header/vector_container.hpp"
#include "../header/selection_sort.hpp"
#include "../header/base.hpp"
#include "../header/op.hpp"
#include "../header/add.hpp"
#include "../header/mult.hpp"

TEST(vectorContainerTest, Add1)
{
    Op *one = new Op(1);
    vectorContainer *test_container = new vectorContainer();
    test_container->add_element(one);
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
}

TEST(vectorContainerTest, Add2)
{
    Op *one = new Op(1);
    Op *two = new Op(2);
    vectorContainer *test_container = new vectorContainer();
    test_container->add_element(one);
    test_container->add_element(two);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 1);
    EXPECT_EQ(test_container->at(1)->evaluate(), 2);
}

TEST(vectorContainerTest, Print1)
{
    Op *three = new Op(3);
    Op *five = new Op(5);
    Add *plus = new Add(three, five);
    vectorContainer *test_container = new vectorContainer();
    test_container->add_element(plus);
    string result = "3 + 5";
    ASSERT_EQ(test_container->size(), 1);
    test_container->print();
}

TEST(vectorContainerTest, Print2)
{
    Op *two = new Op(2);
    Op *three = new Op(3);
    Add *plus = new Add(two, three);
    Op *six = new Op(6);
    Op *eleven = new Op(11);
    Mult *times = new Mult(six, eleven);
    
    vectorContainer *test_container = new vectorContainer();
    test_container->add_element(plus);
    test_container->add_element(times);
    
    string result1 = "2 + 3";
    string result2 = "6 * 11";
    
    ASSERT_EQ(test_container->size(), 2);
    test_container->print();
}

TEST(vectorContainerTest, Swap)
{
    Op *threeptsix = new Op(3.6);
    Op *fourpteight = new Op(4.8);
    vectorContainer *test_container = new vectorContainer();
    test_container->add_element(threeptsix);
    test_container->add_element(fourpteight);
    cout << "Swapping" << endl;
    test_container->swap(0, 1);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 4.8);
    EXPECT_EQ(test_container->at(1)->evaluate(), 3.6);
}

#endif // __VECTOR_CONTAINER_TEST_HPP__