#ifndef FACTORY_TEST
#define FACTORY_TEST
#include "gtest/gtest.h"
#include "../header/factory.hpp"
using namespace std;

TEST(FactoryTest, Add5_6)
{
    char *test_val[4];
    test_val[0] = "./calculator";
    test_val[1] = "5";
    test_val[2] = "+";
    test_val[3] = "6";
    
    Factory *test_factory = new Factory();
    Base *test_base = test_factory->parse(test_val, 4);
    
    string test_result_stringify = test_base->stringify();
    cout << "stringify(): " << test_result_stringify << endl;
    EXPECT_EQ("5 + 6", test_result_stringify);

    double test_result_evaluate = test_base->evaluate();
    cout << "evaluate(): " << test_result_evaluate << endl;
    EXPECT_EQ(11, test_result_evaluate);
}

TEST(FactoryTest2, Sub10_5)
{
    char *test2_val[4];
    test2_val[0] = "./calculator";
    test2_val[1] = "10";
    test2_val[2] = "-";
    test2_val[3] = "5";
    Factory *test_factory = new Factory();
    Base *test_base = test_factory->parse(test2_val, 4);

    string test_result_stringify = test_base->stringify();
    cout << "stringify(): " << test_result_stringify << endl;
    EXPECT_EQ("10 - 5", test_result_stringify);

    double test_result_evaluate = test_base->evaluate();
    cout << "evaluate(): " << test_result_evaluate << endl;
    EXPECT_EQ(5, test_result_evaluate);
}

TEST(FactoryTest3, nullTest)
{
    char *test3_val[4];
    test3_val[0] = "./calculator";
    test3_val[1] = "10";
    test3_val[2] = "X";
    test3_val[3] = "5";

    Factory *test_factory = new Factory();
    Base *test_base = test_factory->parse(test3_val, 4);
    Factory *test_factory_1 = new Factory();
    Base *test_base_1 = test_factory_1->parse(test3_val, 4);

    string test_result_stringify_1 = test_base_1->stringify();
    cout << "stringify(): " << test_result_stringify_1 << endl;
    EXPECT_EQ("10 X 5", test_result_stringify_1);


    cout << "OUTPUT NULLPTR" << endl;
    double test_result_evaluate_1 = test_base_1->evaluate();
    cout << "evaluate(): " << test_result_evaluate_1 << endl;
    EXPECT_NE(0, test_result_evaluate_1);
}


TEST(FactoryTest4, Div10_5)
{
    char *test4_val[4];
    test4_val[0] = "./calculator";
    test4_val[1] = "10";
    test4_val[2] = "/";
    test4_val[3] = "5";

    Factory *test_factory = new Factory();
    Base *test_base = test_factory->parse(test4_val, 4);

    string test_result_stringify = test_base->stringify();
    cout << "stringify(): " << test_result_stringify << endl;
    EXPECT_EQ("10 / 5", test_result_stringify);

    double test_result_evaluate = test_base->evaluate();
    cout << "evaluate(): " << test_result_evaluate << endl;
    EXPECT_EQ(2, test_result_evaluate);
}

TEST(FactoryTest5, Mult10_5)
{
    char *test5_val[4];
    test5_val[0] = "./calculator";
    test5_val[1] = "10";
    test5_val[2] = "*";
    test5_val[3] = "5";

    Factory *test_factory = new Factory();
    Base *test_base = test_factory->parse(test5_val, 4);

    string test_result_stringify = test_base->stringify();
    cout << "stringify(): " << test_result_stringify << endl;
    EXPECT_EQ("10 * 5", test_result_stringify);

    double test_result_evaluate = test_base->evaluate();
    cout << "evaluate(): " << test_result_evaluate << endl;
    EXPECT_EQ(50, test_result_evaluate);
}

#endif /* FACTORY_TEST */
