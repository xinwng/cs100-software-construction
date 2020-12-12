#include "../header/container.hpp"
#include "../header/vector_container.hpp"

// void vectorContainer::add_element(Base *element)
// {
//     v.push_back(element);
// }

void vectorContainer::print()
{
 for(unsigned i = 0; i < v.size(); ++i)
 {
     cout << v.at(i)->stringify() << " ";
 } 
 cout << endl;  
}

// void vectorContainer::sort()
// {
//     try
//     {
//         sort_function->sort(this);
//     }
//     catch(const std::exception& e)
//     {
//         cerr << e.what() << '\n';
//     }
    
// }

void vectorContainer::swap(int i, int j)
{
    Base *a = v.at(i);
    Base *b = v.at(j);
    Base *c = a;
    a = b;
    b = c;
    v.at(i) = a;
    v.at(j) = c;

}

Base* vectorContainer::at(int i)
{
    return v.at(i);
}

// int vectorContainer::size()
// {
//     return v.size();
// }