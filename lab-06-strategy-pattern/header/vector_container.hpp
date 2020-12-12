#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "../header/container.hpp"
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class vectorContainer : public Container
{
private:
    vector<Base *> v;

public:
    vectorContainer(){};
    vectorContainer(Sort *temp)
    { 
        sort_function = temp; 
    }
    // virtual void add_element(Base *element) override;
    void add_element(Base *element)
    {
        v.push_back(element);
    }
    // virtual void print() override;
    void print();
    // virtual void sort() override;
    void sort()
    {
        if (sort_function == NULL)
            throw "No sort function has been set.";
        sort_function->sort(this);
    }
    // virtual void swap(int i, int j) override;
    void swap(int i, int j);
    // virtual Base *at(int i) override;
    Base *at(int i);
    // virtual int size() override;
    int size()
    {
        return v.size();
    }
};

#endif // __VECTOR_CONTAINER_HPP__