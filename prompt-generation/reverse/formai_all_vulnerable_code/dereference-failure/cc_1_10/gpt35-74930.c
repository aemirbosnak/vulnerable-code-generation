//FormAI DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 20

// Task struct containing function pointer and interval time
typedef struct Task {
    void (*function)(void);
    time_t interval;
} Task;

// Array to store scheduled tasks
Task scheduledTasks[MAX_TASKS];

// Function to add a new task to the scheduler
void addTask(void (*function)(void), time_t interval) {
    static int taskCount = 0;

    // Check if the maximum number of tasks has been reached
    if (taskCount == MAX_TASKS) {
        printf("Scheduler maximum capacity reached. Cannot schedule new task.\n");
        return;
    }

    // Initialize the task
    Task newTask;
    newTask.function = function;
    newTask.interval = interval;

    // Add the task to the scheduledTasks array
    scheduledTasks[taskCount++] = newTask;
}

// Function to run the scheduler
void runScheduler() {
    time_t currentTime;
    time(&currentTime);

    // Loop through all scheduled tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        // Get the last run time of the task
        static time_t lastRunTime[MAX_TASKS];
        time_t lastRun = lastRunTime[i];

        // Check if the task needs to be run
        if (difftime(currentTime, lastRun) >= scheduledTasks[i].interval) {
            // Run the task
            scheduledTasks[i].function();

            // Update the last run time
            time(&lastRunTime[i]);
        }
    }
}

// Sample tasks to be scheduled
void taskA() {
    printf("Task A executed.\n");
}

void taskB() {
    printf("Task B executed.\n");
}

void taskC() {
    printf("Task C executed.\n");
}

int main() {
    // Schedule tasks
    addTask(taskA, 1);
    addTask(taskB, 2);
    addTask(taskC, 3);

    // Run tasks every second
    while (1) {
        runScheduler();
        sleep(1);
    }

    return 0;
}