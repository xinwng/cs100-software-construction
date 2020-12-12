#ifndef _LISTCONTAINER_HPP_
#define _LISTCONTAINER_HPP_
#include "../header/container.hpp"
#include "../header/base.hpp"
#include "../header/sort.hpp"
#include <iostream>
#include <list>

using namespace std;
class ListContainer : public Container
{
private:
    list<Base *> list_container;

public:
    ListContainer(){};
    ListContainer(Sort *temp)
    { 
        sort_function = temp; 
    }
    void add_element(Base *element) 
    {
        list_container.push_back(element); 
    }
    void print();
    void sort();
    void swap(int i, int j);
    Base *at(int i);
    int size() 
    { 
        return list_container.size(); 
    }
};
#endif