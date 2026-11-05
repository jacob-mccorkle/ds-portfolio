
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <iomanip>

#include "../Portfolio3A/MinHeap.h"
#include "Task.h"

struct TaskCompare {
    bool operator()(const Task& a, const Task& b) const {
        return b < a;
    }
};

bool sameTask(const Task& a, const Task& b) {
    return a.name == b.name && a.priority == b.priority;
}

void printHeader() {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "          PRIORITY TASK MANAGER         \n";
    std::cout << "========================================\n";
}

void printMenu() {
    std::cout << "\n";
    std::cout << "  1. Add a new task\n";
    std::cout << "  2. Complete next task\n";
    std::cout << "  3. View all tasks\n";
    std::cout << "  4. Exit\n";
    std::cout << "----------------------------------------\n";
    std::cout << "  Select an option: ";
}

int main() {
    MinHeap<Task> tasks;
    std::priority_queue<Task, std::vector<Task>, TaskCompare> reference;

    std::string choice;

    while (true) {
        printHeader();

        std::cout << "  Tasks waiting: " << tasks.size() << "\n";

        printMenu();
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::string name;
            std::string priorityInput;
            int priority;

            std::cout << "\n--- ADD NEW TASK ---\n";
            std::cout << "Enter task name: ";
            std::getline(std::cin, name);

            if (name.empty()) {
                std::cout << "Task name cannot be empty.\n";
                continue;
            }

            std::cout << "Enter priority (higher number = more important): ";
            std::getline(std::cin, priorityInput);

            std::istringstream parser(priorityInput);

            if (!(parser >> priority)) {
                std::cout << "Please enter a valid number.\n";
                continue;
            }

            parser >> std::ws;

            if (!parser.eof()) {
                std::cout << "Please enter a valid whole number.\n";
                continue;
            }

            Task task{name, priority};

            tasks.insert(task);
            reference.push(task);

            std::cout << "\nTask successfully added!\n";
            std::cout << "Name: " << name << "\n";
            std::cout << "Priority: " << priority << "\n";
        }
        else if (choice == "2") {
            std::cout << "\n--- NEXT TASK ---\n";

            if (tasks.isEmpty()) {
                std::cout << "There are no tasks waiting.\n";
                continue;
            }

            Task myTask = tasks.extractMin();

            Task referenceTask = reference.top();
            reference.pop();

            std::cout << "Completed task: " << myTask.name << "\n";
            std::cout << "Priority: " << myTask.priority << "\n";

            if (sameTask(myTask, referenceTask)) {
                std::cout << "Cross-check: PASS\n";
            }
            else {
                std::cout << "Cross-check: FAIL\n";
            }
        }
        else if (choice == "3") {
            std::cout << "\n--- CURRENT TASK LIST ---\n";

            if (tasks.isEmpty()) {
                std::cout << "There are no tasks waiting.\n";
                continue;
            }

            MinHeap<Task> heapCopy = tasks;
            auto referenceCopy = reference;

            std::cout << "\n";
            std::cout << std::left
                      << std::setw(5) << "#"
                      << std::setw(25) << "TASK"
                      << "PRIORITY\n";

            std::cout << "----------------------------------------\n";

            bool passed = true;
            int number = 1;

            while (!heapCopy.isEmpty() && !referenceCopy.empty()) {
                Task myTask = heapCopy.extractMin();

                Task referenceTask = referenceCopy.top();
                referenceCopy.pop();

                std::cout << std::left
                          << std::setw(5) << number
                          << std::setw(25) << myTask.name
                          << myTask.priority << "\n";

                if (!sameTask(myTask, referenceTask)) {
                    passed = false;
                }

                number++;
            }

            if (!heapCopy.isEmpty() || !referenceCopy.empty()) {
                passed = false;
            }

            std::cout << "----------------------------------------\n";

            if (passed) {
                std::cout << "STL Cross-check: PASS\n";
            }
            else {
                std::cout << "STL Cross-check: FAIL\n";
            }
        }
        else if (choice == "4") {
            std::cout << "\nThanks for using Priority Task Manager!\n";
            break;
        }
        else {
            std::cout << "\nInvalid option. Please choose 1-4.\n";
        }

        std::cout << "\nPress Enter to continue...";
        std::string pause;
        std::getline(std::cin, pause);
    }

    return 0;
}
