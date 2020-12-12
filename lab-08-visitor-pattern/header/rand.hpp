#ifndef __RAND_HPP__
#define __RAND_HPP__
#include "../header/base.hpp"
#include <iostream>
#include <sstream>

// using namespace std;

class Rand : public Base
{
public:
    Rand(double value) : Base()
    {
        this->value = rand() % 100;
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
        std::cout << "returning nullptr" << std::endl;
        return nullptr;
    }
    Base *get_right()
    {
        std::cout << "returning nullptr" << std::endl;
        return nullptr;
    }
    void accept(CountVisitor *temp)
    {
        temp->visit_rand(this);
    }

private:
    double value;
};

#endif //__RAND_HPP__
