#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

struct Action
{
    string type;
    string text;
};

void clearStack(Stack<Action>& stack)
{
    while (!stack.isEmpty())
    {
        stack.pop();
    }
}

int main()
{
    string document;
    Stack<Action> undoStack;
    Stack<Action> redoStack;

    string command;

    while (true)
    {
        cout << "> ";
        cin >> command;

        if (command == "TYPE")
        {
            string text;
            getline(cin, text);

            if (!text.empty() && text[0] == ' ')
            {
                text.erase(0, 1);
            }

            if (!text.empty())
            {
                document += text;

                Action action;
                action.type = "TYPE";
                action.text = text;

                undoStack.push(action);
                clearStack(redoStack);
            }
        }
        else if (command == "DELETE")
        {
            int n;
            cin >> n;

            if (n > 0 && !document.empty())
            {
                int amount = n;

                if (amount > static_cast<int>(document.length()))
                {
                    amount = document.length();
                }

                string deleted = document.substr(
                    document.length() - amount,
                    amount
                );

                document.erase(
                    document.length() - amount,
                    amount
                );

                Action action;
                action.type = "DELETE";
                action.text = deleted;

                undoStack.push(action);
                clearStack(redoStack);
            }
        }
        else if (command == "UNDO")
        {
            if (!undoStack.isEmpty())
            {
                Action action = undoStack.pop();

                if (action.type == "TYPE")
                {
                    document.erase(
                        document.length() - action.text.length()
                    );
                }
                else if (action.type == "DELETE")
                {
                    document += action.text;
                }

                redoStack.push(action);
            }
        }
        else if (command == "REDO")
        {
            if (!redoStack.isEmpty())
            {
                Action action = redoStack.pop();

                if (action.type == "TYPE")
                {
                    document += action.text;
                }
                else if (action.type == "DELETE")
                {
                    document.erase(
                        document.length() - action.text.length()
                    );
                }

                undoStack.push(action);
            }
        }
        else if (command == "PRINT")
        {
            cout << document << endl;
        }
        else if (command == "QUIT")
        {
            break;
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }

    return 0;
}
