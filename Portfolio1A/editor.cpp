#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

struct Action
{
    string type;
    string text;

    Action()
    {
        type = "";
        text = "";
    }

    Action(string t, string s)
    {
        type = t;
        text = s;
    }
};

void typeText(string& document, Stack<Action>& undoStack,
              Stack<Action>& redoStack, const string& text)
{
    document += text;

    // A new action clears the redo stack
    while (!redoStack.isEmpty())
    {
        redoStack.pop();
    }

    // Save the action for undo
    undoStack.push(Action("TYPE", text));
}

void deleteText(string& document, Stack<Action>& undoStack,
                Stack<Action>& redoStack, int amount)
{
    if (amount <= 0 || document.empty())
        return;

    if (amount > static_cast<int>(document.length()))
        amount = document.length();

    // Save the text that is being deleted
    string deletedText = document.substr(document.length() - amount);

    // Delete from the end of the document
    document.erase(document.length() - amount);

    // A new action clears the redo stack
    while (!redoStack.isEmpty())
    {
        redoStack.pop();
    }

    // Save the action for undo
    undoStack.push(Action("DELETE", deletedText));
}

void undo(string& document, Stack<Action>& undoStack,
          Stack<Action>& redoStack)
{
    if (undoStack.isEmpty())
    {
        cout << "Nothing to undo." << endl;
        return;
    }

    Action action = undoStack.pop();

    if (action.type == "TYPE")
    {
        // Undo TYPE by removing the text that was typed
        document.erase(document.length() - action.text.length());
    }
    else if (action.type == "DELETE")
    {
        // Undo DELETE by putting the deleted text back
        document += action.text;
    }

    // Save the action so it can be redone
    redoStack.push(action);
}

void redo(string& document, Stack<Action>& undoStack,
          Stack<Action>& redoStack)
{
    if (redoStack.isEmpty())
    {
        cout << "Nothing to redo." << endl;
        return;
    }

    Action action = redoStack.pop();

    if (action.type == "TYPE")
    {
        // Redo TYPE
        document += action.text;
    }
    else if (action.type == "DELETE")
    {
        // Redo DELETE
        document.erase(document.length() - action.text.length());
    }

    // Put the action back on the undo stack
    undoStack.push(action);
}

void printDocument(const string& document)
{
    cout << document << endl;
}

int main()
{
    string document = "";

    Stack<Action> undoStack;
    Stack<Action> redoStack;

    string command;

    cout << "Text Editor" << endl;
    cout << "Commands: TYPE, DELETE, UNDO, REDO, PRINT, QUIT" << endl;

    while (true)
    {
        cout << "> ";
        cin >> command;

        if (command == "TYPE")
        {
            string text;

            getline(cin, text);

            // Remove the space between TYPE and the text
            if (!text.empty() && text[0] == ' ')
                text.erase(0, 1);

            typeText(document, undoStack, redoStack, text);
        }
        else if (command == "DELETE")
        {
            int amount;
            cin >> amount;

            deleteText(document, undoStack, redoStack, amount);
        }
        else if (command == "UNDO")
        {
            undo(document, undoStack, redoStack);
        }
        else if (command == "REDO")
        {
            redo(document, undoStack, redoStack);
        }
        else if (command == "PRINT")
        {
            printDocument(document);
        }
        else if (command == "QUIT")
        {
            break;
        }
        else
        {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}
