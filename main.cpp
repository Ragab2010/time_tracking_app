#include <iostream>
#include "authentication.h"
#include "dashboard.h"
#include "task.h"
#include "project.h"
#include "time_tracking.h"
#include "reporting.h"

int main() {
    // Create a user and authenticate
    User user("john_doe", "password");
    if (!user.authenticate()) {
        std::cout << "Authentication failed. Exiting...\n";
        return 1;
    }

    // Create tasks
    Task task1("Task 1", 2);
    Task task2("Task 2", 1);
    Task task3("Task 3", 3);

    // Create a dashboard
    Dashboard dashboard;
    dashboard.addTask(task1);
    dashboard.addTask(task2);
    dashboard.addTask(task3);

    // Create a project and add milestones
    Project project("Project A", "Project Manager");
    Milestone milestone1("Milestone 1", "2023-12-31");
    Milestone milestone2("Milestone 2", "2024-03-15");
    project.addMilestone(milestone1);
    project.addMilestone(milestone2);

    // Create a time tracker
    TimeTracker timeTracker;
    timeTracker.addTask(task1);
    timeTracker.addTask(task2);
    timeTracker.addTask(task3);

    // Start and stop timers
    timeTracker.startTimer(task1);
    timeTracker.startTimer(task2);
    timeTracker.stopTimer(task1);
    timeTracker.startTimer(task3);
    timeTracker.stopTimer(task2);
    timeTracker.stopTimer(task3);

    // Generate a time tracking report
    ReportGenerator reportGenerator(timeTracker);
    reportGenerator.generateReport();

    return 0;
}
