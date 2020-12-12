#ifndef _LISTCONTAINER_CPP_
#define _LISTCONTAINER_CPP_
#include "../header/list_container.hpp"
#include <iostream>

using namespace std;
void ListContainer::print()
{
    list<Base *>::iterator temp;
    for (temp = list_container.begin(); temp != list_container.end(); temp++)
    {
        Base *x = *temp;
        cout << x->stringify() << endl;
    }
}

void ListContainer::sort()
{
    if (sort_function == NULL)
        throw "No sort function has been set yet.";
    sort_function->sort(this);
}

void ListContainer::swap(int i, int j)
{
    list<Base *>::iterator temp;
    int count1 = 0;
    int count2 = 0;
    Base *m_Base1;
    Base *m_Base2;
    for (temp = list_container.begin(); temp != list_container.end(); temp++)
    {
        if (count1 == i)
        {
            m_Base1 = *temp;
        }
        if (count1 == j)
        {
            m_Base2 = *temp;
        }
        count1++;
        count2++;
    }
    count1 = 0;
    count2 = 0;
    for (temp = list_container.begin(); temp != list_container.end(); temp++)
    {
        if (count1 == i)
        {
            *temp = m_Base2;
        }
        if (count1 == j)
        {
            *temp = m_Base1;
        }
        count1++;
        count2++;
    }
}
Base *ListContainer::at(int i)
{
    list<Base *>::iterator temp;
    int temp_counter = 0;
    for (temp = list_container.begin(); temp != list_container.end(); temp++)
    {
        if (temp_counter == i)
        {
            return *temp;
        }
        temp_counter++;
    }
    return *temp;
}
#endif