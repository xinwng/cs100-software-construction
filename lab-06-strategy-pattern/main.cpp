#include <iostream>
#include <vector>

#include "header/base.hpp"
#include "header/op.hpp"
#include "header/rand.hpp"
#include "header/mult.hpp"
#include "header/div.hpp"
#include "header/add.hpp"
#include "header/sub.hpp"
#include "header/pow.hpp"
#include "header/sort.hpp"
#include "src/bubble_sort.cpp"
#include "src/container.cpp"
#include "src/selection_sort.cpp"
#include "src/vector_container.cpp"
#include "src/list_container.cpp"

using namespace std;
int main() {
    Op* seven = new Op(7);
    Op* three = new Op(3);
    Op *two = new Op(2);
    Op* five = new Op(5);
    Mult* testA = new Mult(seven, three);
    Add* testB = new Add(testA, three);
    Sub* testC = new Sub(testB, two);
    Div* testD = new Div(testC, two);
    vectorContainer *container = new vectorContainer();
    container->add_element(testA);
    container->add_element(testB);
    container->add_element(testC);
    container->add_element(testD);

    cout << "testA located at index 0 evaluates to: " << container->at(0)->evaluate() << endl;
    cout << "testB located at index 1 evaluates to: " << container->at(1)->evaluate() << endl;
    cout << "testC located at index 2 evaluates to: " << container->at(2)->evaluate() << endl;
    cout << "testD located at index 3 evaluates to: " << container->at(3)->evaluate() << endl;

    cout << "Container Before Sort:" << endl;
    container->print();
    cout << "Container After Sort:" << endl;
    container->set_sort_function(new selectionSort());
    container->sort();
    container->print();

    cout << "testA located at index 0 evaluates to: " << container->at(0)->evaluate() << endl;
    cout << "testB located at index 1 evaluates to: " << container->at(1)->evaluate() << endl;
    cout << "testC located at index 2 evaluates to: " << container->at(2)->evaluate() << endl;
    cout << "testD located at index 3 evaluates to: " << container->at(3)->evaluate() << endl;


    cout << endl << endl;

    ListContainer *container_list = new ListContainer();
    Op *six = new Op(6);
    Op *four = new Op(4);
    Op *one = new Op(1);
    Op *eight = new Op(8);

    container_list->add_element(six);
    container_list->add_element(four);
    container_list->add_element(one);
    container_list->add_element(eight);

    cout << "container_list located at index 0 evaluates to: " << container_list->at(0)->evaluate() << endl;
    cout << "container_list located at index 1 evaluates to: " << container_list->at(1)->evaluate() << endl;
    cout << "container_list located at index 2 evaluates to: " << container_list->at(2)->evaluate() << endl;
    cout << "container_list located at index 3 evaluates to: " << container_list->at(3)->evaluate() << endl;

    cout << "container_list Before Sort:" << endl;
    container_list->print();
    cout << "container_list After Sort:" << endl;
    container_list->set_sort_function(new bubbleSort());
    container_list->sort();
    container_list->print();
    return 0;
}
