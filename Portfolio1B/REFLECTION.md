# Portfolio 1B Reflection

For this portfolio, I built a text editor simulator using my own `Stack<T>` class. The main goal was to use stacks to keep track of actions so that the program could support undo and redo.

The part I found most important was understanding how the two stacks work together. The undo stack keeps track of changes that have been made to the document. When I use `UNDO`, the most recent action is removed from the undo stack and placed on the redo stack. When I use `REDO`, that action is taken from the redo stack and put back onto the undo stack. I also had to make sure that making a new change clears the redo stack.

One part that required more thought was figuring out what information needed to be saved for each action. For a `TYPE` command, I needed to save the text that was added. For a `DELETE` command, I needed to save the text that was deleted so that it could be restored if the action was undone. This helped me understand why stacks are useful for keeping track of a history of actions.

I also had to make sure my `Stack<T>` followed the Rule of Three. This included the copy constructor, assignment operator, and destructor. Working with dynamically allocated nodes made it important to properly copy the nodes instead of just copying the pointer to the first node.

This portfolio helped me understand stacks better because I was using one to solve an actual problem instead of just testing individual stack operations. I also got more practice with templates, dynamic memory, and managing objects correctly.

One thing I could improve is adding the optional file-loading feature and undo/redo count reporting. The required text editor functionality works, but I did not implement the optional bonus features.