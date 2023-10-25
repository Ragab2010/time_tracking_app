#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono> // Include the <chrono> library

struct TimeEntry {
    std::chrono::seconds mStartTime{0};
    std::chrono::seconds mtotalTime{0};
    bool mIsTracking{false};
};

class Task {
public:
    Task(const std::string& title, int priority , int duration );
    const std::string& getTitle() const;
    int getPriority() const;
    const std::chrono::minutes& getDuration() const; // Added for task duration
    bool operator==(const Task& other) const;

    // mTime methods
    bool isTracking() const;
    void setTracking(bool traking)const;
    void setStartTime(std::chrono::seconds start)const;
    void setTotalTime(std::chrono::seconds total)const;
    std::chrono::seconds getTotalTime()const;

private:
    std::string title;
    int priority;
    std::chrono::minutes duration; // Added for task duration
    mutable TimeEntry mTime;
    
};

#endif
