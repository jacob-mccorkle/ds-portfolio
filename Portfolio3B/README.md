# Portfolio 3B – Priority Task Scheduler and Word Frequency Counter

## Overview

Portfolio 3B uses the MinHeap and HashTable implementations from Portfolio 3A to solve two problems.

### Part 1: Priority Task Scheduler

The task scheduler stores tasks using a MinHeap.

Each task contains:
- A name
- A priority

Higher priority numbers are handled first. If two tasks have the same priority, their names are ordered alphabetically.

Commands:
- `ADD name priority` adds a task.
- `NEXT` removes and displays the highest-priority task.
- `LIST` displays all remaining tasks in priority order.
- `EXIT` ends the program.

The scheduler also uses `std::priority_queue` to compare extraction results against the custom MinHeap.

### Part 2: Word Frequency Counter

The word frequency program reads a text file and counts how often each word appears.

It:
- Converts words to lowercase.
- Ignores punctuation.
- Stores word counts in the custom HashTable.
- Compares the results against `std::unordered_map`.
- Uses the custom MinHeap to display the 10 most frequent words.

Words with equal counts are displayed alphabetically.

## Files

- `Task.h`: Defines the Task structure and priority comparison.
- `scheduler.cpp`: Implements the priority task scheduler.
- `word_frequency.cpp`: Implements the word frequency counter.
- `Makefile`: Compiles both programs.

## Compilation

Compile both programs using:

`make`

Run the scheduler:

`./scheduler`

Run the word frequency counter:

`./word_frequency sample.txt`

Clean compiled programs:

`make clean`

## Testing

The scheduler was designed to compare its extraction order against `std::priority_queue`.

The word frequency counter compares its word counts against `std::unordered_map`.

Both programs report whether their cross-checks pass or fail.

## Priority Rules

Higher numeric priority values come first.

For example:
- Priority 10 comes before priority 5.
- Priority 5 comes before priority 1.
- Equal priorities are ordered alphabetically.