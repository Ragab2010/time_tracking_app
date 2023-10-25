#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

class Milestone {
public:
    Milestone(const std::string name, const std::string dueDate);
    const std::string& getName() const;
    const std::string& getDueDate() const;
private:
    std::string name;
    std::string dueDate;
};

class Project {
public:
    Project(const std::string name, const std::string manager);
    const std::string& getName() const;
    const std::string& getManager() const;
    void addMilestone(const Milestone& milestone);
private:
    std::string name;
    std::string manager;
    std::vector<Milestone> milestones;
};

#endif
