#include <iostream>
#include <string>

#include "MinHeap.h"
#include "HashTable.h"

int main() {

  std::cout << "Testing MinHeap..." << std::endl;

    MinHeap<int> heap;

    heap.insert(8);
    heap.insert(3);
    heap.insert(10);
    heap.insert(1);

    std::cout << "Minimum: " << heap.peek() << std::endl;

    std::cout << "Extracted values: ";

    while (!heap.isEmpty()) {
        std::cout << heap.extractMin() << " ";
    }

    std::cout << std::endl;

    std::cout << "Heap size: " << heap.size() << std::endl;

        std::cout << "\nTesting HashTable..." << std::endl;

    HashTable<std::string, int> table;

    table.insert("apple", 10);
    table.insert("banana", 20);
    table.insert("orange", 30);
    table.insert("grape", 40);

    const int* appleValue = table.find("apple");

    if (appleValue != nullptr) {
        std::cout << "apple: " << *appleValue << std::endl;
    }

    table.insert("apple", 15);

    appleValue = table.find("apple");

    if (appleValue != nullptr) {
        std::cout << "Updated apple: "
                  << *appleValue << std::endl;
    }

    std::cout << "Removed banana: "
              << (table.remove("banana") ? "yes" : "no")
              << std::endl;

    std::cout << "Table size: " << table.size() << std::endl;

    std::cout << "Bucket count: "
              << table.bucketCount() << std::endl;

    std::cout << "Load factor: "
              << table.loadFactor() << std::endl;

    return 0;
}
