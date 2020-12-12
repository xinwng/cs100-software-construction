#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__
#include "../header/container.hpp"
#include "../header/base.hpp"
#include "../header/sort.hpp"
#include <iostream>
#include <vector>

class bubbleSort : public Sort
{
    public:
        bubbleSort(){};
        void sort(Container *container);
};


#endif //__BUBBLE_SORT_HPP__
