#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:

    struct Node
    {
        T value;
        Node* next;

        Node(const T& value, Node* next = nullptr)
        {
            this->value = value;
            this->next = next;
        }
    };

    Node* head;
    int count;

public:

    // Constructor
    LinkedList()
    {
        head = nullptr;
        count = 0;
    }

    // Push to front
    void pushFront(const T& value)
    {
        head = new Node(value, head);
        count++;
    }

    // Push to back
    void pushBack(const T& value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;

            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
        }

        count++;
    }

    // Pop from front
    void popFront()
    {
        if (head == nullptr)
        {
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
        count--;
    }

    // Remove a value
    bool remove(const T& value)
    {
        if (head == nullptr)
        {
            return false;
        }

        if (head->value == value)
        {
            popFront();
            return true;
        }

        Node* current = head;

        while (current->next != nullptr)
        {
            if (current->next->value == value)
            {
                Node* temp = current->next;
                current->next = temp->next;

                delete temp;
                count--;

                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Check if value exists
    bool contains(const T& value) const
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Return size
    int size() const
    {
        return count;
    }

    // Check if empty
    bool isEmpty() const
    {
        return head == nullptr;
    }

    // Print list
    void print() const
    {
        Node* current = head;

        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Destructor
    ~LinkedList()
    {
        while (head != nullptr)
        {
            popFront();
        }
    }

    // Copy Constructor
    LinkedList(const LinkedList& other)
    {
        head = nullptr;
        count = 0;

        Node* current = other.head;

        while (current != nullptr)
        {
            pushBack(current->value);
            current = current->next;
        }
    }

    // Assignment Operator
    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)
        {
            while (head != nullptr)
            {
                popFront();
            }

            Node* current = other.head;

            while (current != nullptr)
            {
                pushBack(current->value);
                current = current->next;
            }
        }

        return *this;
    }

    // Iterator
    class Iterator
    {
    private:
        Node* current;

    public:

        Iterator(Node* node)
        {
            current = node;
        }

        // Prefix ++
        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        // Dereference *
        T& operator*()
        {
            return current->value;
        }

        // Not equal !=
        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }
    };

    // Begin iterator
    Iterator begin()
    {
        return Iterator(head);
    }

    // End iterator
    Iterator end()
    {
        return Iterator(nullptr);
    }
};

#endif
