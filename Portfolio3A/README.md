# Portfolio 3A: MinHeap and HashTable

## What Was Built

This project contains two template data structures
implemented from scratch.

### MinHeap

MinHeap<T> uses a std::vector<T> to store a binary min-heap.

It provides:

- insert(const T&)
- extractMin()
- peek() const
- size() const
- isEmpty() const

The heapifyUp and heapifyDown functions restore the
min-heap property after insertion and extraction.

The smallest value is always stored at index 0.

extractMin() and peek() throw std::underflow_error
if the heap is empty.

### HashTable

HashTable<K, V> uses a vector of linked lists.

Each list stores key-value pairs, allowing multiple
keys to map to the same bucket through separate chaining.

It provides:

- insert(const K&, const V&)
- find(const K&)
- remove(const K&)
- size() const
- isEmpty() const
- loadFactor() const
- bucketCount() const

Inserting an existing key updates its value.

Find returns a pointer to the value or nullptr if
the key does not exist.

Remove returns true if an entry was removed and
false if the key was not found.

### Hash Function

For string keys, the table uses a polynomial hash function.

The hash starts at zero and processes each character using:

hash = hash * 31 + character

The multiplier 31 makes character order matter.

The resulting hash is converted into a bucket index
using the modulo operator and the number of buckets.

Other key types use std::hash<K>.

### Rehashing

The maximum load factor is 0.75.

When the load factor exceeds 0.75, the hash table
increases its bucket count to:

2 * oldBucketCount + 1

All existing entries are redistributed into their
new buckets.

## Compilation on Ludwig

Run:

g++ -std=c++17 -Wall -Wextra -pedantic test_main.cpp -o test_main

Then run:

./test_main

## Known Limitations

- MinHeap requires its data type to support the
  less-than operator.
- HashTable requires keys to support equality comparison.
- String keys use the custom polynomial hash function.
- Other key types use the standard library hash function.