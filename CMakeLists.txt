cmake_minimum_required(VERSION 3.10)

project(TimeTrackingApp)

# Set the C++ standard explicitly
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define your source files
set(SOURCE_FILES
    main.cpp
    src/authentication.cpp
    src/dashboard.cpp
    src/task.cpp
    src/project.cpp
    src/time_tracking.cpp
    src/reporting.cpp
)

# Define your header files
set(HEADER_FILES
    include/authentication.h
    include/dashboard.h
    include/task.h
    include/project.h
    include/time_tracking.h
    include/reporting.h
)

# Create the executable
add_executable(TimeTrackingApp ${SOURCE_FILES} ${HEADER_FILES})

# Set include directories
target_include_directories(TimeTrackingApp PRIVATE include)
