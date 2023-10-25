#include "reporting.h"
#include <iostream>

ReportGenerator::ReportGenerator(const TimeTracker& timeTracker) : timeTracker(timeTracker) {}

void ReportGenerator::generateReport() const {
    std::cout << "************ Time Tracking Report ************\n";
    for (const TimeEntry& timeEntry : timeTracker.getTimeEntries()) {
        const Task& task = timeEntry.getTask();
        std::chrono::seconds totalTime = timeEntry.getTimeSpent();

        std::cout << "Task: " << task.getTitle() << "\n";
        std::cout << "Time Spent: " << totalTime.count() << " seconds\n";
        std::cout << "--------------------------\n";
    }
    std::cout << "***************************************\n";
}
