#ifndef __OP_HPP__
#define __OP_HPP__
#include "../header/base.hpp"
#include <iostream>
#include <sstream>

// using namespace std;
class Op : public Base
{
public:
    Op(double value) : Base()
    {
        this->value = value;
    }
    double evaluate()
    {
        return value;
    }
    std::string stringify()
    {
        std::ostringstream oss;
        oss << value;
        std::string oss_value = oss.str();
        return oss_value;
    }
    Iterator *create_iterator()
    {
        return new NullIterator(this);
    }
    Base *get_left()
    {
        return nullptr;
    }
    Base *get_right()
    {
        return nullptr;
    }
    void accept(CountVisitor *temp)
    {
        temp->visit_op(this);
    }

private:
    double value;
};

#endif //__OP_HPP__
