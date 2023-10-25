#include "reporting.h"
#include <iostream>
#include <chrono>

ReportGenerator::ReportGenerator(const TimeTracker& timeTracker) : timeTracker(timeTracker) {}

void ReportGenerator::generateReport() const {
    std::cout << "************ Time Tracking Report ************\n";

    // Retrieve tasks by priority
    std::vector<Task> tasksByPriority = timeTracker.getTasksByPriority();

    for (const Task& task : tasksByPriority) {
                std::cout << "Task: " << task.getTitle() << "\n";
                std::cout << "Time Spent: " << std::chrono::duration_cast<std::chrono::seconds>(task.getTotalTime()).count() << " seconds\n";
                std::cout << "Priority: " << task.getPriority() << "\n";
                std::cout << "--------------------------\n";
    }
    std::cout << "***************************************\n";
}
