#include "dashboard.h"
#include <iostream>

void Dashboard::addTask(const Task& task) {
    tasks.push_back(task);
}

void Dashboard::displayDashboard() const {
    std::cout << "************ Task Dashboard ************\n";
    for (const Task& task : tasks) {
        std::cout << "Title: " << task.getTitle() << "\n";
        std::cout << "Priority: " << task.getPriority() << "\n";
        std::cout << "--------------------------\n";
    }
    std::cout << "***************************************\n";
}
