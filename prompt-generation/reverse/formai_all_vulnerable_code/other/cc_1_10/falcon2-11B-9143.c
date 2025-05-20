//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get current time in seconds since epoch
double getCurrentTime() {
    time_t rawtime;
    struct tm *info;
    double seconds;

    // Get current time
    time(&rawtime);

    // Convert to tm struct
    info = localtime(&rawtime);

    // Calculate seconds since epoch
    seconds = (double)info->tm_sec + (double)info->tm_min * 60 + (double)info->tm_hour * 3600;

    return seconds;
}

// Function to schedule a task to be executed at a specific time
void scheduleTask(double time, void (*task)()) {
    // Get current time
    double currentTime = getCurrentTime();

    // Check if task time is in the past
    if (time < currentTime) {
        printf("Task scheduled for a time in the past, skipping...\n");
        return;
    }

    // Get remaining time until task time
    double remainingTime = time - currentTime;

    // Wait until task time
    sleep(remainingTime);

    // Execute task
    task();

    // Schedule next task if there is one
    scheduleTask(time + 5, scheduleTask);
}

int main() {
    void (*task)();
    task = scheduleTask;

    // Schedule first task
    task();

    return 0;
}