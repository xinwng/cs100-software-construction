#ifndef FACTORY
#define FACTORY
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include <cstring>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Base;
class Factory
{
    public:
        Factory(){};
        Base *parse(char **input, int length);
};


#endif /* FACTORY */
