//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_DELAY 3600 // 1 hour

// Structure to store tasks
typedef struct {
    char *name;
    int delay;
    int started;
} task_t;

// Global variables
task_t tasks[MAX_TASKS];
int num_tasks;

// Function to add a task to the scheduler
void add_task(char *name, int delay) {
    task_t *task = malloc(sizeof(task_t));
    task->name = name;
    task->delay = delay;
    task->started = 0;
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached\n");
        return;
    }
    tasks[num_tasks] = *task;
    num_tasks++;
}

// Function to start a task
void start_task(int index) {
    if (index < 0 || index >= num_tasks) {
        printf("Error: Invalid task index\n");
        return;
    }
    tasks[index].started = 1;
}

// Function to check if a task is done
int is_task_done(int index) {
    if (index < 0 || index >= num_tasks) {
        printf("Error: Invalid task index\n");
        return 0;
    }
    return tasks[index].started;
}

// Function to schedule the tasks
void schedule_tasks() {
    for (int i = 0; i < num_tasks; i++) {
        if (!tasks[i].started && tasks[i].delay > 0) {
            // Calculate the current time
            time_t now = time(NULL);
            int delay = tasks[i].delay;
            int next_run = now + delay;

            // Check if the task should run now
            if (next_run <= now) {
                start_task(i);
            }
        }
    }
}

int main() {
    // Add some tasks to the scheduler
    add_task("Task 1", 300); // 300 seconds = 5 minutes
    add_task("Task 2", 1800); // 1800 seconds = 3 hours
    add_task("Task 3", 2700); // 2700 seconds = 4.5 hours

    // Schedule the tasks
    schedule_tasks();

    // Main loop to run the tasks
    while (1) {
        schedule_tasks();
        sleep(1); // 1 second
    }

    return 0;
}