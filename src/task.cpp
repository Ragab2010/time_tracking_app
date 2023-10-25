#include "task.h"



Task::Task(const std::string& title, int priority ,int duration  )
    : title(title), priority(priority), duration(std::chrono::minutes(duration)), mTime() {}

const std::string& Task::getTitle() const {
    return title;
}

int Task::getPriority() const {
    return priority;
}

const std::chrono::minutes& Task::getDuration() const {
    return duration;
}


bool Task::operator==(const Task& other) const {
    return (title == other.title && priority == other.priority);
}



bool Task::isTracking() const{
    return mTime.mIsTracking;
}
void Task::setTracking(bool traking) const {
    mTime.mIsTracking = traking;
}

void Task::setStartTime(std::chrono::seconds start)const {
    mTime.mStartTime = start;
}
void Task::setTotalTime(std::chrono::seconds total)const {
    mTime.mtotalTime = total;
}

std::chrono::seconds Task::getTotalTime()const{
    return  mTime.mtotalTime;
}