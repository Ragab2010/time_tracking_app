#include <iostream>
#include <chrono>
#include "authentication.h"
#include "dashboard.h"
#include "task.h"
#include "project.h"
#include "time_tracking.h"
#include "reporting.h"
#include "cli.h"

using namespace std::chrono;

int main() {

    TimeTracker timeTracker;
    std::vector<Task> tasks;

    while (true) {
        std::cout << "Time Tracking Application Menu:" << std::endl;
        std::cout << "1. Add a task with priority and time (in minutes)" << std::endl;
        std::cout << "2. Start executing tasks based on priority" << std::endl;
        std::cout << "3. Generate a time tracking report" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskTitle;
                int priority;
                int minutes;

                std::cout << "Enter task title: ";
                std::cin.ignore();
                std::getline(std::cin, taskTitle);
                std::cout << "Enter task priority: ";
                std::cin >> priority;
                std::cout << "Enter task time (in minutes): ";
                std::cin >> minutes;

                Task newTask(taskTitle, priority , minutes);

                tasks.push_back(newTask);
                // timeTracker.addTask(newTask);
                std::cout << "Added task: " << taskTitle << " with priority " << priority << " and time " << minutes << " minutes." << std::endl;
                break;
            }

            case 2: {
                //set tasks for timerTracker
                timeTracker.setTasks(tasks);
                if (tasks.empty()) {
                    std::cerr << "No tasks to execute. Please add tasks with priorities and times." << std::endl;
                    break;
                }

                std::cout << "Executing tasks based on priority:" << std::endl;
                timeTracker.startExcuteTasks();

                break;
            }

            case 3: {
                ReportGenerator reportGenerator(timeTracker);
                reportGenerator.generateReport();
                break;
            }

            case 4: {
                std::cout << "Goodbye!" << std::endl;
                return 0;
            }

            default:
                std::cerr << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
