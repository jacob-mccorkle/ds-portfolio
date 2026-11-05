#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
    std::string name;
    int priority;

    bool operator<(const Task& other) const {
        if (priority != other.priority) {
            return priority > other.priority;
        }

        return name < other.name;
    }
};

#endif
