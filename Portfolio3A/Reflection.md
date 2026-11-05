# Portfolio 3A Reflection

## What I Built

For Part A, I implemented the core data structures used in the portfolio: a min-heap and a hash table. The min-heap stores elements in a vector and maintains heap order so that the smallest element can be accessed and removed efficiently. The hash table uses separate chaining to handle collisions, with each bucket storing a list of entries.

## What I Learned

This part helped me understand how data structures organize information and how their operations depend on maintaining specific rules. With the min-heap, insertion requires placing an element in the next available position and moving it upward when necessary. Removing the minimum requires replacing the root and restoring heap order. With the hash table, I learned how a hash function determines a bucket and how separate chaining allows multiple keys to share a bucket when collisions occur.

I also gained practice working with templates, vectors, lists, and pointers. In particular, returning a pointer from `find` makes it possible to access or update a stored value without searching for it again.

## Challenges

One challenge was keeping the data structure's internal organization correct after insertions and removals. A heap can contain all the correct values but still be incorrect if the parent-child ordering is broken. A hash table also needs careful handling when a key is already present, when a key is removed, and when multiple keys map to the same bucket.

Testing was important because small mistakes in indexing, comparisons, or pointer handling can cause errors that are difficult to notice from a single example.

## How I Tested It

I used the provided tests and additional test cases to check the main operations. I also used compiler warnings and memory checking where appropriate to help identify problems. Testing different insertion, removal, lookup, and collision situations helped confirm that the structures behaved as expected.

## What I Would Improve

If I continued improving this part, I would add more edge-case tests, especially for empty structures, repeated keys, collisions, and operations performed after removals. I would also continue practicing how to translate the logic of an operation into C++ syntax so that I can implement similar data structures more independently.