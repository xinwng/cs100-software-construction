#ifndef __RAND_HPP__
#define __RAND_HPP__
#include "../header/base.hpp"
#include <iostream>
#include <sstream>

using namespace std;
class Rand : public Base{
public:
    Rand(double value) : Base(){
        this->value = rand() % 100;
    }
    virtual double evaluate(){
        return value;
    }
    virtual string stringify(){
        ostringstream oss;
        oss << value;
        string oss_value = oss.str();
        return oss_value;
    }
private:
    double value;
};

#endif //__RAND_HPP__
