#include "project.h"

Milestone::Milestone(const std::string& name, const std::string& dueDate)
    : name(name), dueDate(dueDate) {}

const std::string& Milestone::getName() const {
    return name;
}

const std::string& Milestone::getDueDate() const {
    return dueDate;
}

Project::Project(const std::string name, const std::string manager)
    : name(std::move(name)), manager(std::move(manager)) {}

const std::string& Project::getName() const {
    return name;
}

const std::string& Project::getManager() const {
    return manager;
}

void Project::addMilestone(const Milestone& milestone) {
    milestones.push_back(milestone);
}
