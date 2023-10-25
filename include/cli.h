#ifndef CLI_H
#define CLI_H

#include "time_tracking.h"
#include "reporting.h"

class CommandLineInterface {
public:
    CommandLineInterface(TimeTracker& timeTracker);
    void run(int argc, char* argv[]);
private:
    TimeTracker& timeTracker;
};

#endif
