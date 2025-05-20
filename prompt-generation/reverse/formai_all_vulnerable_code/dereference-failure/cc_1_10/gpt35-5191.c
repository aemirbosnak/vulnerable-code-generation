//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the struct for each task to be scheduled
typedef struct Task {
    int interval;   // time interval in seconds
    int executed;   // flag to indicate whether task has been executed or not
    void (*function)(void); // function pointer to the task to be executed
} Task;

// function to be executed every minute
void minuteTask() {
    printf("Minute task executed!\n");
}

// function to be executed every 5 seconds
void fiveSecondsTask() {
    printf("Five second task executed!\n");
}

// function to be executed every 30 seconds
void thirtySecondsTask() {
    printf("Thirty second task executed!\n");
}

// function to initialize a new Task struct
Task* newTask(int interval, void (*function)(void)) {
    Task* task = (Task*)malloc(sizeof(Task)); // allocate memory for the new Task
    task->interval = interval;
    task->executed = 0;
    task->function = function;
    return task;
}

int main() {
    // initialize the tasks we want to schedule
    Task* minute = newTask(60, &minuteTask);
    Task* fiveSeconds = newTask(5, &fiveSecondsTask);
    Task* thirtySeconds = newTask(30, &thirtySecondsTask);

    // keep track of the current time
    time_t currentTime;
    int previousMinute = -1; // keep track of the previous minute to run tasks that execute every minute

    while (1) { // run forever
        currentTime = time(NULL); // update current time

        // check if it's time to execute the minute task
        if (previousMinute != localtime(&currentTime)->tm_min) {
            previousMinute = localtime(&currentTime)->tm_min;
            if (minute->executed == 0) {
                minute->function(); // execute minute task
                minute->executed = 1;
            }
        } else {
            minute->executed = 0; // reset executed flag if minute hasn't changed
        }

        // check if it's time to execute the five second task
        if (localtime(&currentTime)->tm_sec % fiveSeconds->interval == 0) {
            if (fiveSeconds->executed == 0) {
                fiveSeconds->function(); // execute five second task
                fiveSeconds->executed = 1;
            }
        } else {
            fiveSeconds->executed = 0; // reset executed flag if not time to execute
        }

        // check if it's time to execute the thirty second task
        if (localtime(&currentTime)->tm_sec % thirtySeconds->interval == 0) {
            if (thirtySeconds->executed == 0) {
                thirtySeconds->function(); // execute thirty second task
                thirtySeconds->executed = 1;
            }
        } else {
            thirtySeconds->executed = 0; // reset executed flag if not time to execute
        }

        // sleep for one second before checking the time again
        sleep(1);
    }

    return 0;
}