#ifndef VISITOR_TEST
#define VISITOR_TEST
#include "gtest/gtest.h"
#include "../header/iterator.hpp"
#include "../header/visitor.hpp"
#include "../header/add.hpp"
#include "../header/base.hpp"
#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/pow.hpp"
#include "../header/rand.hpp"
#include "../header/sub.hpp"
#include <iostream>

using namespace std;

TEST(get_left_right_test, AddTest)
{
	Base *one = new Op(1);
	Base *two = new Op(2);
	Base *add1 = new Add(one, two);
	cout << "get_left()->: " << add1->get_left()->evaluate() << " get_right()->: " << add1->get_right()->evaluate() << endl;
	EXPECT_EQ(add1->get_left()->evaluate(), 1);
	EXPECT_EQ(add1->get_right()->evaluate(), 2);
	cout << "add1->evaluate(): " << add1->evaluate() << endl;
	EXPECT_EQ(add1->evaluate(), 3);
}

TEST(get_left_right_test, SubTest)
{
	Base *five = new Op(5);
	Base *twenty_five = new Op(25);
	Base *sub1 = new Sub(five, twenty_five);
	cout << "get_left()->: " << sub1->get_left()->evaluate() << " get_right()->: " << sub1->get_right()->evaluate() << endl;
	EXPECT_EQ(sub1->get_left()->evaluate(), 5);
	EXPECT_EQ(sub1->get_right()->evaluate(), 25);
	cout << "sub1->evaluate(): " << sub1->evaluate() << endl;
	EXPECT_EQ(sub1->evaluate(), -20);
}

TEST(get_left_right_test, MultTest)
{
	Base *thirty_three = new Op(33);
	Base *two = new Op(2);
	Base *mult1 = new Mult(thirty_three, two);
	cout << "get_left()->: " << mult1->get_left()->evaluate() << " get_right()->: " << mult1->get_right()->evaluate() << endl;
	EXPECT_EQ(mult1->get_left()->evaluate(), 33);
	EXPECT_EQ(mult1->get_right()->evaluate(), 2);
	cout << "mult1->evaluate(): " << mult1->evaluate() << endl;
	EXPECT_EQ(mult1->evaluate(), 66);
}

TEST(get_left_right_test, DivTest)
{
	Base *sixty = new Op(60);
	Base *ten = new Op(10);
	Base *div1 = new Div(sixty, ten);
	cout << "get_left()->: " << div1->get_left()->evaluate() << " get_right()->: " << div1->get_right()->evaluate() << endl;
	EXPECT_EQ(div1->get_left()->evaluate(), 60);
	EXPECT_EQ(div1->get_right()->evaluate(), 10);
	cout << "div1->evaluate(): " << div1->evaluate() << endl;
	EXPECT_EQ(div1->evaluate(), 6);
}

TEST(get_left_right_test, PowTest)
{
	Base *nine = new Op(9);
	Base *two = new Op(2);
	Base *pow1 = new Pow(nine, two);
	cout << "get_left()->: " << pow1->get_left()->evaluate() << " get_right()->: " << pow1->get_right()->evaluate() << endl;
	EXPECT_EQ(pow1->get_left()->evaluate(), 9);
	EXPECT_EQ(pow1->get_right()->evaluate(), 2);
	cout << "pow1->evaluate(): " << pow1->evaluate() << endl;
	EXPECT_EQ(pow1->evaluate(), 81);
}

// TEST(get_left_right_test, NullTest)
// {
// 	Base *four = new Op(4);
// 	Base *eight = new Op(8);
// 	cout << "get_left()->: " << four->get_left()->evaluate() << " get_right()->: " << eight->get_right()->evaluate() << endl;
// 	cout << "expected nullptr, segmentation fault" << endl;
// 	EXPECT_NE(four->get_left()->evaluate(), 4);
// 	EXPECT_NE(eight->get_left()->evaluate(), 8);
// }

TEST(VisitorTest, PreorderIteratorTest)
{
	Op *three = new Op(3);
	Op *five = new Op(5);
	Op *two = new Op(2);
	Op *one = new Op(1);
	Sub *sub1 = new Sub(three, five);
	// 3 - 5 = -2
	Div *div1 = new Div(two, one);
	// 2 / 1 = 2
	Add *add1 = new Add(sub1, div1);
	// -2 + 2 = 0

	CountVisitor *m_CountVisitor1 = new CountVisitor;
	PreorderIterator *m_PreOrderIterator1 = new PreorderIterator(add1);
	m_PreOrderIterator1->first();

	while (m_PreOrderIterator1->is_done() == false)
	{
		m_PreOrderIterator1->current()->accept(m_CountVisitor1);
		m_PreOrderIterator1->next();
	}

	EXPECT_EQ(m_CountVisitor1->sub_count(), 1);
	EXPECT_EQ(m_CountVisitor1->div_count(), 1);
	EXPECT_EQ(m_CountVisitor1->op_count(), 4);
}

TEST(VisitorTest, IteratorTest)
{
	Base *zero = new Op(0);
	Base *one = new Op(1);
	Base *two = new Op(2);
	Base *three = new Op(3);
	Base *four = new Op(4);
	Base *five = new Op(5);
	Base *six = new Op(6);
	Base *seven = new Op(7);
	Base *eight = new Op(8);
	Base *nine = new Op(9);

	Base *a1 = new Add(one, two);
	Base *a2 = new Add(three, six);
	Base *a3 = new Add(four, seven);
	Base *a4 = new Add(five, eight);
	Base *s5 = new Sub(nine, one);
	Base *s6 = new Sub(eight, six);
	Base *s7 = new Sub(two, three);
	Base *d8 = new Div(nine, three);
	Base *d9 = new Div(nine, a1);
	Base *m10 = new Mult(two, s5);
	Base *m11 = new Mult(s6, d8);
	Base *p12 = new Pow(a2, a1);
	Base *dummy = new Add(p12, m11);

	Iterator *It = new PreorderIterator(dummy);
	It->first();
	CountVisitor *Visit = new CountVisitor;

	while (!It->is_done())
	{
		It->current()->accept(Visit);
		It->next();
	}

	int OpResult = 8;
	int AddResult = 2;
	int SubResult = 1;
	int DivResult = 1;
	int MultResult = 1;
	int PowResult = 1;

	EXPECT_EQ(OpResult, Visit->op_count());
	EXPECT_EQ(AddResult, Visit->add_count());
	EXPECT_EQ(SubResult, Visit->sub_count());
	EXPECT_EQ(DivResult, Visit->div_count());
	EXPECT_EQ(MultResult, Visit->mult_count());
	EXPECT_EQ(PowResult, Visit->pow_count());
}

TEST(CreateIteratorTest, AddTest_BinaryIterator)
{
	Base *ci_test_99 = new Op(99);
	Base *ci_test_1 = new Op(1);
	Base *ci_test_add_99_1 = new Add(ci_test_99, ci_test_1);
	Base *ci_test_dummy_1 = new Add(ci_test_add_99_1, new Op(0));

	CountVisitor *ci_test_visitor = new CountVisitor;
	Iterator *ci_test_binary_iterator = new BinaryIterator(ci_test_dummy_1);
	ci_test_binary_iterator->first();

	while (!ci_test_binary_iterator->is_done())
	{
		ci_test_binary_iterator->current()->accept(ci_test_visitor);
		ci_test_binary_iterator->next();
	}

	cout << "ADD_COUNT - EXPECTED : 1"
		 << " RECEIVED: " << ci_test_visitor->add_count() << endl;
	EXPECT_EQ(ci_test_visitor->add_count(), 1);
	cout << "OP_COUNT - EXPECTED : 1"
		 << " RECEIVIED: " << ci_test_visitor->op_count() << endl;
	EXPECT_EQ(ci_test_visitor->op_count(), 1);
}

#endif /* VISITOR_TEST */
