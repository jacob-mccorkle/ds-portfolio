#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:

    struct Node
    {
        T data;
        Node* next;

        Node(const T& value, Node* next = nullptr)
        {
            data = value;
            this->next = next;
        }
    };

    Node* topNode;
    int count;

public:

    // Constructor
    Stack()
    {
        topNode = nullptr;
        count = 0;
    }

    // Push
    void push(const T& value)
    {
        topNode = new Node(value, topNode);
        count++;
    }

    // Pop
    T pop()
    {
        if (topNode == nullptr)
        {
            return T();
        }

        Node* temp = topNode;
        T value = temp->data;

        topNode = topNode->next;

        delete temp;
        count--;

        return value;
    }

    // Top
    T& top()
    {
        return topNode->data;
    }

    // Check if empty
    bool isEmpty() const
    {
        return topNode == nullptr;
    }

    // Return size
    int size() const
    {
        return count;
    }

    // Destructor
    ~Stack()
    {
        while (topNode != nullptr)
        {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Copy Constructor
    Stack(const Stack& other)
    {
        topNode = nullptr;
        count = 0;

        if (other.topNode == nullptr)
        {
            return;
        }

        // First copy the nodes into a temporary stack
        Stack<T> temp;

        Node* current = other.topNode;

        while (current != nullptr)
        {
            temp.push(current->data);
            current = current->next;
        }

        // Put them back in the correct order
        while (!temp.isEmpty())
        {
            push(temp.pop());
        }
    }

    // Assignment Operator
    Stack& operator=(const Stack& other)
    {
        if (this == &other)
        {
            return *this;
        }

        // Delete current nodes
        while (topNode != nullptr)
        {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }

        count = 0;

        if (other.topNode == nullptr)
        {
            return *this;
        }

        // Copy the other stack
        Stack<T> temp;

        Node* current = other.topNode;

        while (current != nullptr)
        {
            temp.push(current->data);
            current = current->next;
        }

        while (!temp.isEmpty())
        {
            push(temp.pop());
        }

        return *this;
    }
};

#endif
