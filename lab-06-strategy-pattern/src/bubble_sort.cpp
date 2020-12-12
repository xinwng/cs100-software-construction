#include <vector>
#include "../header/container.hpp"
#include "../header/vector_container.hpp"
#include "../header/sort.hpp"
#include "../header/bubble_sort.hpp"

void bubbleSort::sort(Container *c)
{
    int i, j = 1;
    int num = 1;
    int container_size = c->size();
    for (i = 1; (i <= (container_size) && num); i++)
    {
        num = 0;
        for (j = 0; j < (container_size - 1); j++)
        {
            if (c->at(j + 1)->evaluate() > c->at(j)->evaluate())
            {
                c->swap(j, j + 1);
                num = 1;
            }
        }
    }
    return;
}