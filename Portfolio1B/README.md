# Portfolio 1B - Text Editor Simulator

## What I Built

For Portfolio 1B, I built a text-editing simulator using my own `Stack<T>` class. The program uses two stacks to keep track of undo and redo actions.

The text editor supports:

- `TYPE <text>` - adds text to the document
- `DELETE <n>` - deletes the last `n` characters
- `UNDO` - reverses the most recent document change
- `REDO` - reapplies the most recently undone change
- `PRINT` - prints the current document
- `QUIT` - exits the program

Every time the document is changed, an undo record is added to the undo stack. When an action is undone, it is moved to the redo stack. If a new change is made after an undo, the redo stack is cleared.

## Files

- `Stack.h` - My templated Stack class with push, pop, top, isEmpty, size, copy constructor, assignment operator, and destructor.
- `main.cpp` - The text editor simulator and command processing.
- `Makefile` - Compiles the program.

## How to Compile

On `ludwig.mcs.uvawise.edu`, run:

    make

Or compile directly with:

    g++ -Wall -Wextra -std=c++17 main.cpp -o portfolio1b

## How to Run

After compiling:

    ./portfolio1b

Example commands:

    TYPE Hello
    PRINT
    TYPE World
    PRINT
    DELETE 5
    PRINT
    UNDO
    PRINT
    REDO
    PRINT
    QUIT

## Known Limitations

The text editor works with the required commands and keeps track of undo and redo operations. The program does not include the optional file-loading bonus feature.