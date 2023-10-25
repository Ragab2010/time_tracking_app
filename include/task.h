#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string title, int priority);
    const std::string& getTitle() const;
    int getPriority() const;
        // Add operator== to compare Task instances
    [[nodiscard]] bool operator==(const Task& other) const;
private:
    std::string title;
    int priority;
};

#endif
