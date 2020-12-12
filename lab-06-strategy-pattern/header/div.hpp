#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "../header/base.hpp"
#include "../header/op.hpp"
#include <iostream>

using namespace std;
class Div : public Base
{
public:
    Div(Base* left_child, Base* right_child) : Base()
    {
        this->left_child = left_child;
        this->right_child = right_child;
    }
    double evaluate()
    {
        return left_child->evaluate() / right_child->evaluate();
    }
    string stringify()
    {
        ostringstream oss;
        oss << left_child->stringify() << " / " << right_child->stringify();
        string oss_value = oss.str();
        return oss_value;
    }

private:
    Base* left_child;
    Base* right_child;
};
#endif //__MULT_HPP__
