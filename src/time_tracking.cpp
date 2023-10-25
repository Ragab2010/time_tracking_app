#include "time_tracking.h"

TimeEntry::TimeEntry(const Task& task)
    : task(task), totalTime(0), isTracking(false) {}

void TimeEntry::startTimer() {
    if (!isTracking) {
        startTime = std::chrono::system_clock::now();
        isTracking = true;
    }
}

void TimeEntry::stopTimer() {
    if (isTracking) {
        std::chrono::time_point<std::chrono::system_clock> endTime = std::chrono::system_clock::now();
        totalTime += std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
        isTracking = false;
    }
}

std::chrono::seconds TimeEntry::getTimeSpent() const {
    return totalTime;
}

void TimeTracker::addTask(const Task& task) {
    TimeEntry timeEntry(task);
    timeEntries.push_back(timeEntry);
}

bool TimeTracker::startTimer(const Task& task) {
    for (TimeEntry& entry : timeEntries) {
        if (entry.getTask() == task) {
            entry.startTimer();
            return true;
        }
    }
    return false;
}

bool TimeTracker::stopTimer(const Task& task) {
    for (TimeEntry& entry : timeEntries) {
        if (entry.getTask() == task) {
            entry.stopTimer();
            return true;
        }
    }
    return false;
}

const std::vector<TimeEntry>& TimeTracker::getTimeEntries() const {
    return timeEntries;
}

const Task& TimeEntry::getTask() const{
    return task;
}