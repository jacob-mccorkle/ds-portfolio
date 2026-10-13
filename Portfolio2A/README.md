# Portfolio 1A: Templated Linked List

## Description

This project implements a templated `LinkedList<T>` class in C++. The linked list stores elements in dynamically allocated nodes, with each node pointing to the next node in the list.

The class supports inserting, removing, searching, and accessing elements. It also implements the Rule of Three to properly manage dynamically allocated memory and includes an iterator for traversing the list.

## Features

- Templated linked list that supports different data types.
- Insert elements at the front and back.
- Remove the first element.
- Search for values in the list.
- Check the size of the list and whether it is empty.
- Print the elements in the list.
- Deep copy using a copy constructor and copy assignment operator.
- Destructor to release dynamically allocated memory.
- Iterator support for traversing the list.

## Files

- `LinkedList.h` — Contains the templated linked list implementation.
- `main.cpp` — Demonstrates and tests the linked list.
- `Makefile` — Compiles the program.

## Compile and Run on Ludwig

Navigate to the Portfolio1A directory:

```bash
cd ~/ds-portfolio/Portfolio1A
```

Compile the program:

```bash
make
```

Run the executable:

```bash
./main
```

If the executable has a different name, check the target in the Makefile.

## Memory Management

The linked list uses dynamic memory allocation for its nodes. The destructor releases all nodes when the list is destroyed. The copy constructor and copy assignment operator perform deep copies so that separate lists manage their own nodes independently.

## Testing

The main program tests the linked list's operations, including insertion, removal, searching, copying, and traversal.

## Known Limitations

The list is singly linked, so moving forward through the list is supported, but moving backward is not directly supported.