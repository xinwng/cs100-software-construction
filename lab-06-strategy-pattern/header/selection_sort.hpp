#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__
#include "../header/container.hpp"
#include "../header/base.hpp"
#include "../header/sort.hpp"
#include <iostream>
#include <vector>

class selectionSort : public Sort
{
    public:
        selectionSort(){};
        void sort(Container *container);
};

#endif //__SELECTION_SORT_HPP__