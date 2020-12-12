#include <vector>
#include "../header/container.hpp"
#include "../header/vector_container.hpp"
#include "../header/sort.hpp"
#include "../header/selection_sort.hpp"

using namespace std;
void selectionSort::sort(Container *container)
{
    if (!container->size())
    {
        return;
    }

    unsigned int j;

    for (unsigned int i = 0; i < container->size(); ++i)
    {
        unsigned int minVal = i;

        for (j = i + 1; j < container->size(); ++j)
        {
            if (container->at(j)->evaluate() < container->at(minVal)->evaluate())
            {
                minVal = j;
            }
        }

        container->swap(i, minVal);
    }
};