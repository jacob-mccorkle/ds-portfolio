#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
{
    // Create an integer list
    LinkedList<int> list;

    cout << "Is the list empty? " << list.isEmpty() << endl;

    // Test pushBack
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    cout << "List after pushBack: ";
    list.print();

    // Test pushFront
    list.pushFront(5);

    cout << "List after pushFront: ";
    list.print();

    // Test size
    cout << "Size: " << list.size() << endl;

    // Test contains
    cout << "Contains 20? " << list.contains(20) << endl;
    cout << "Contains 50? " << list.contains(50) << endl;

    // Test remove
    list.remove(20);

    cout << "List after removing 20: ";
    list.print();

    // Test popFront
    list.popFront();

    cout << "List after popFront: ";
    list.print();

    // Test copy constructor
    LinkedList<int> list2 = list;

    cout << "Copied list: ";
    list2.print();

    // Test assignment operator
    LinkedList<int> list3;
    list3 = list;

    cout << "Assigned list: ";
    list3.print();

    // Test iterator
    cout << "Using iterator: ";

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    // Test range-based for loop
    cout << "Using range-based for loop: ";

    for (int value : list)
    {
        cout << value << " ";
    }

    cout << endl;

    // Test string list
    LinkedList<string> names;

    names.pushBack("Jacob");
    names.pushBack("John");
    names.pushBack("Mike");

    cout << "String list: ";
    names.print();

    return 0;
}
