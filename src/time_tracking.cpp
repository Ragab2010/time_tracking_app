#include <algorithm>
#include <iostream>
#include <chrono>
#include "time_tracking.h"


// TimeTracker methods
// TimeTracker::TimeTracker(std::vector<Task>& tasks):tasks(tasks) {}

// bool TimeTracker::startTimer(const Task& task) {
//     for (TimeEntry& entry : timeEntries) {
//         if (entry.getTask() == task && !entry.isTracking()) {
//             entry.setTracking( true);
//             return true;
//         }
//     }
//     return false;
// }

// bool TimeTracker::stopTimer(const Task& task) {
//     for (TimeEntry& entry : timeEntries) {
//         if (entry.getTask() == task && entry.isTracking()) {
//             entry.setTracking( false);
//             return true;
//         }
//     }
//     return false;
// }

std::vector<Task> TimeTracker::getTasksByPriority() const {
    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
    });
    return sortedTasks;
}


void TimeTracker::setTasks(std::vector<Task>& move_tasks){
    tasks = move_tasks;
}


void TimeTracker::startExcuteTasks()  {
    // Sort the tasks based on priority
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
    });

    // Loop and execute the tasks one by one
    for ( const Task& task : tasks) {
        std::cout << "Task: " << task.getTitle() << " (Priority: " << task.getPriority() << ", Time: " << task.getDuration().count() << " minutes)" << std::endl;

        // Start a timer here and display live execution time
        auto start_time = std::chrono::system_clock::now();
        task.setStartTime(std::chrono::duration_cast<std::chrono::seconds>(start_time.time_since_epoch()));
        auto end_time = start_time + task.getDuration();
        task.setTotalTime(std::chrono::duration_cast<std::chrono::seconds>(end_time.time_since_epoch()));

        while (std::chrono::system_clock::now() < end_time) {
            auto elapsed_time = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::system_clock::now() - start_time);
            std::cout << "Time elapsed: " << elapsed_time.count() << " minutes\r";
            std::cout.flush();
        }
        std::cout << "Task completed." << std::endl;
    }
}
