#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <vector>
#include "task.h"

class Dashboard {
public:
    void addTask(const Task& task);
    void displayDashboard() const;
private:
    std::vector<Task> tasks;
};

#endif
