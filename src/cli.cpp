#include "cli.h"
#include <iostream>
#include "cxxopts.hpp"

CommandLineInterface::CommandLineInterface(TimeTracker& timeTracker)
    : timeTracker(timeTracker) {}

void CommandLineInterface::run(int argc, char* argv[]) {
    cxxopts::Options options("TimeTrackingApp", "A time tracking and task management application");
    options.add_options()
        ("h,help", "Show help")
        ("add-task", "Add a new task", cxxopts::value<std::string>())
        ("start-timer", "Start tracking time for a task", cxxopts::value<std::string>())
        ("stop-timer", "Stop tracking time for a task", cxxopts::value<std::string>())
        ("generate-report", "Generate a time tracking report")
        ;

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return;
    }

    if (result.count("add-task")) {
        std::string taskTitle = result["add-task"].as<std::string>();
        // Add priority as needed
        Task newTask(taskTitle,1  , 0);
        timeTracker.addTask(newTask);
        std::cout << "Added task: " << taskTitle << std::endl;
    }

    if (result.count("start-timer")) {
        std::string taskTitle = result["start-timer"].as<std::string>();
        if (timeTracker.startTimer(Task(taskTitle, 0))) {
            std::cout << "Started timer for task: " << taskTitle << std::endl;
        } else {
            std::cout << "Task not found: " << taskTitle << std::endl;
        }
    }

    if (result.count("stop-timer")) {
        std::string taskTitle = result["stop-timer"].as<std::string>();
        if (timeTracker.stopTimer(Task(taskTitle, 0))) {
            std::cout << "Stopped timer for task: " << taskTitle << std::endl;
        } else {
            std::cout << "Task not found: " << taskTitle << std::endl;
        }
    }

    if (result.count("generate-report")) {
        ReportGenerator reportGenerator(timeTracker);
        reportGenerator.generateReport();
    }
}

//////////////////////
