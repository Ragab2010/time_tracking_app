#ifndef REPORTING_H
#define REPORTING_H

#include "time_tracking.h"

class ReportGenerator {
public:
    ReportGenerator(const TimeTracker& timeTracker);
    void generateReport() const;
private:
    const TimeTracker& timeTracker;
};

#endif

