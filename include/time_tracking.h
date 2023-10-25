#ifndef TIME_TRACKING_H
#define TIME_TRACKING_H

#include "task.h"
#include <vector>
#include <chrono>

class TimeTracker {
public:
    TimeTracker()=default;
    void setTasks(std::vector<Task>& move_tasks);
    bool startTimer();
    bool stopTimer();
    std::vector<Task> getTasksByPriority() const;
    const std::vector<TimeEntry>& getTimeEntries() const;
    void startExcuteTasks();

private:
    std::vector<Task> tasks;
    
};

#endif
