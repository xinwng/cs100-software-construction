#ifndef __POW_HPP__
#define __POW_HPP__
#include "../header/base.hpp"
#include "../header/op.hpp"
#include <iostream>
#include <cmath>

using namespace std;
class Pow : public Base{
public:
        Pow(Base* left_child, Base* right_child) : Base(){
                this->left_child = left_child;
                this->right_child = right_child;
        }
        double evaluate(){
		return pow(left_child->evaluate(), right_child->evaluate());
        }
        string stringify(){
                ostringstream oss;
                oss << left_child->stringify() << " ** " << right_child->stringify();
                string oss_value = oss.str();
                return oss_value;
        }
private:
        Base* left_child;
        Base* right_child;
};
#endif //__POW_HPP__
