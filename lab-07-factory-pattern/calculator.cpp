#include <iostream>
#include <vector>
#include <list>

#include "header/add.hpp"
#include "header/base.hpp"
#include "header/div.hpp"
#include "header/mult.hpp"
#include "header/op.hpp"
#include "header/pow.hpp"
#include "header/rand.hpp"
#include "header/sub.hpp"
#include "header/factory.hpp"

using namespace std;

int main(int argv, char **argc)
{
    Factory *m_factory = new Factory();
    Base *result = m_factory->parse(argc, argv);
    if(result != nullptr)
    {
        cout << "stringify(): " << result->stringify() << endl;
        cout << "evaluate(): " << result->evaluate() << endl;
    }
    else
    {
        cout << "nullptr" << endl;
    }
}