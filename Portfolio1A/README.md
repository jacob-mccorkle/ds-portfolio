# Portfolio 1A - Linked List

## What I Built

For Portfolio 1A, I built a templated linked list class in C++. The list uses dynamically allocated nodes to store values and provides functions for adding, removing, searching, and accessing elements.

The linked list supports:

- `pushFront()` - adds a value to the front of the list
- `pushBack()` - adds a value to the end of the list
- `popFront()` - removes the first value
- `remove()` - removes a specific value
- `contains()` - checks if a value is in the list
- `size()` - returns the number of elements
- `isEmpty()` - checks if the list is empty
- Iterators for moving through the list

The class also follows the Rule of Three with a copy constructor, assignment operator, and destructor.

## Files

- `LinkedList.h` - My templated linked list class.
- `main.cpp` - Tests the linked list functionality.
- `Makefile` - Compiles the program.

## How to Compile

On `ludwig.mcs.uvawise.edu`, run:

    make

Or compile directly with:

    g++ -Wall -Wextra -std=c++17 main.cpp -o portfolio1a

## How to Run

After compiling:

    ./portfolio1a

## Known Limitations

The program focuses on the required linked list functionality and testing. It does not include features outside of the requirements for Portfolio 1A.