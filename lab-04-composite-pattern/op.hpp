#ifndef __OP_HPP__
#define __OP_HPP__
#include "base.hpp"
#include <iostream>
#include <sstream>

using namespace std;
class Op : public Base {
    public:
        Op(double value) : Base(){
            this->value = value;
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

#endif //__OP_HPP__
