#include "task.h"

Task::Task(const std::string title, int priority)
    : title(std::move(title)), priority(priority) {}

const std::string& Task::getTitle() const {
    return title;
}

int Task::getPriority() const {
    return priority;
}

[[nodiscard]] bool Task::operator==(const Task& other) const {
    return (title == other.title && priority == other.priority);
}