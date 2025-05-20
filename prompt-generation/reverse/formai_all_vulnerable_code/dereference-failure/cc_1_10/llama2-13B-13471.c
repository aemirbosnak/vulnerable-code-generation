//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 20

// Structure to hold task information
typedef struct {
    char name[TASK_NAME_LEN];
    void (*function)(void);
    bool running;
} task_t;

// Array to hold tasks
task_t tasks[MAX_TASKS];

// Current task index
int curr_task = 0;

// Function to schedule a task
void schedule_task(void (*function)(void), char *name) {
    task_t *task = (task_t *)malloc(sizeof(task_t));
    task->function = function;
    strcpy(task->name, name);
    task->running = false;
    tasks[curr_task] = *task;
    curr_task++;
}

// Function to check if a task is running
bool is_task_running(void) {
    for (int i = 0; i < curr_task; i++) {
        if (tasks[i].running) {
            return true;
        }
    }
    return false;
}

// Function to start a task
void start_task(void) {
    if (is_task_running()) {
        printf("Error: Cannot start a new task while another task is already running.\n");
        return;
    }
    tasks[curr_task - 1].running = true;
    printf("Started task: %s\n", tasks[curr_task - 1].name);
}

// Function to stop a task
void stop_task(void) {
    if (!is_task_running()) {
        printf("Error: No task is running to stop.\n");
        return;
    }
    tasks[curr_task - 1].running = false;
    printf("Stopped task: %s\n", tasks[curr_task - 1].name);
}

// Function to print the list of tasks
void print_tasks(void) {
    for (int i = 0; i < curr_task; i++) {
        if (tasks[i].running) {
            printf("%d. %s (running)\n", i + 1, tasks[i].name);
        } else {
            printf("%d. %s (idle)\n", i + 1, tasks[i].name);
        }
    }
}

int main(void) {
    // Schedule some tasks
    schedule_task(print_tasks, "Print tasks");
    schedule_task(start_task, "Start task");
    schedule_task(stop_task, "Stop task");

    // Start the scheduler
    start_task();

    // Wait for the scheduler to finish
    while (1) {
        // Do nothing
    }

    return 0;
}