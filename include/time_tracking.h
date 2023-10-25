#ifndef TIME_TRACKING_H
#define TIME_TRACKING_H

#include <vector>
#include "task.h"
#include <chrono>
#include <utility>

class TimeEntry {
public:
    TimeEntry(const Task& task);
    void startTimer();
    void stopTimer();
    std::chrono::seconds getTimeSpent() const;
    const Task& getTask() const;
private:
    Task task;
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::seconds totalTime;
    bool isTracking;
};

class TimeTracker {
public:
    void addTask(const Task& task);
    bool startTimer(const Task& task);
    bool stopTimer(const Task& task);
    //
    const std::vector<TimeEntry>& getTimeEntries() const;
private:
    std::vector<TimeEntry> timeEntries;
};

#endif
