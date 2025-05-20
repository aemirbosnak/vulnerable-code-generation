//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

// Task structure
typedef struct task {
    char *command;  // Command to be executed
    time_t start_time;  // Start time of the task
    int interval;  // Interval between executions (in seconds)
} task_t;

// Task list
task_t *tasks;
int num_tasks;

// SIGALRM handler
void alarm_handler(int signo) {
    // Loop through the tasks and execute any that are due
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time <= time(NULL)) {
            // Start the task
            system(tasks[i].command);
            
            // Update the next start time of the task
            tasks[i].start_time += tasks[i].interval;
        }
    }
    
    // Set the next alarm
    alarm(1);
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize the task list
    tasks = NULL;
    num_tasks = 0;

    // Parse the command-line arguments
    for (int i = 1; i < argc; i++) {
        // Get the command and interval
        char *command = argv[i];
        int interval = 0;
        if (i + 1 < argc) {
            interval = atoi(argv[i + 1]);
        }

        // Create a new task
        task_t task = {
            .command = command,
            .start_time = time(NULL),
            .interval = interval,
        };

        // Add the task to the list
        tasks = realloc(tasks, (num_tasks + 1) * sizeof(task_t));
        tasks[num_tasks++] = task;

        // Increment the argument counter
        i++;
    }

    // Set up the SIGALRM handler
    signal(SIGALRM, alarm_handler);

    // Set the first alarm
    alarm(1);

    // Main loop
    while (1) {
        // Sleep until the next alarm
        pause();
    }

    // Clean up
    free(tasks);

    return 0;
}