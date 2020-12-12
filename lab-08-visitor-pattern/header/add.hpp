#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "../header/base.hpp"
#include <iostream>
#include <sstream>
#include <string>

class Add : public Base
{
public:
        Add(Base *left_child, Base *right_child) : Base()
        {
                this->left_child = left_child;
                this->right_child = right_child;
        }
        double evaluate()
        {
                return left_child->evaluate() + right_child->evaluate();
        }
        std::string stringify()
        {
                std::ostringstream oss;
                oss << left_child->stringify() << " + " << right_child->stringify();
                std::string oss_value = oss.str();
                return oss_value;
        }
        Iterator *create_iterator()
        {
                return new BinaryIterator(this);
        }
        Base *get_left()
        {
                if (left_child)
                {
                        return this->left_child;
                }
                else
                {
                        return nullptr;
                }
        }
        Base *get_right()
        {
                if (right_child)
                {
                        return this->right_child;
                }
                else
                {
                        return nullptr;
                }
        }
        void accept(CountVisitor *temp)
        {
                temp->visit_add(this);
        }

private:
        Base *left_child;
        Base *right_child;
};
#endif //__ADD_HPP__
