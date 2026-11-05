# Portfolio 3B Reflection

## What I Built

For Part B, I used the data structures from Part A in two applications. The priority task scheduler uses the custom min-heap to organize tasks by priority. The word frequency program reads a text file, converts words to lowercase, counts them with the custom hash table, and uses the min-heap to display the ten most frequent words.

I also compared the results with standard library containers. The scheduler checks its task order against `std::priority_queue`, and the word frequency program checks its counts against `std::unordered_map`.

## What I Learned

This part helped me see how data structures can be used to solve larger problems rather than only being tested through individual operations. The scheduler showed how a heap can support a priority-based application. The word frequency program showed how a hash table can make it practical to find and update counts by word.

I also learned that comparison functions affect the order in which elements are processed. For the scheduler, I used a comparison rule so that a larger numeric priority is treated as more important. For the word frequency program, the comparison rule places words with higher counts first and uses alphabetical order to break ties.

Another important lesson was the value of checking a custom implementation against a standard library implementation. The cross-checks provide a way to catch errors that might not be obvious from looking at the output.

## Challenges

One challenge was connecting the existing data structures to the programs that use them. I had to understand which operations the applications needed and how to call the custom heap and hash table correctly.

Formatting the terminal interface also required care. The display code needed to be placed inside the correct function, and the appropriate headers had to be included for output formatting. Compiler errors helped identify these issues and reinforced the importance of understanding where code belongs in a C++ program.

## How I Tested It

I compiled both programs using the Makefile and tested the scheduler by adding tasks with different priorities, listing them, and completing the next task. I checked that the custom heap produced the same order as the standard priority queue.

For the word frequency program, I tested it with a text file containing repeated words and punctuation. I checked the displayed counts and the HashTable cross-check against `std::unordered_map`.

## What I Would Improve

If I continued improving this part, I would add more test files with punctuation, capitalization, ties between word counts, and fewer than or more than ten unique words. I would also test the scheduler with tasks that have equal priorities and with an empty task list.

Overall, Part B helped me connect the concepts from Part A to practical programs. It also showed me that understanding the logic is only one part of programming; I need to keep improving at turning that logic into correct C++ syntax and testing the result.