#include "../header/container.hpp"
#include "../header/vector_container.hpp"
#include "../header/base.hpp"


void Container::set_sort_function(Sort *sort_function)
{
    this->sort_function = sort_function;
}
