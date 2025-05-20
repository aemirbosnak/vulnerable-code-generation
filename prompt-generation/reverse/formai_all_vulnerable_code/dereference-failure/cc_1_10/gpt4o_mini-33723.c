//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int duration;  // Duration of the task in seconds
    int time_slice; // Time slice allocated per execution
    int elapsed_time; // Time already executed
} Task;

typedef struct {
    Task *tasks[MAX_TASKS];
    int count; // Number of tasks
} TaskScheduler;

TaskScheduler* create_scheduler() {
    TaskScheduler *scheduler = malloc(sizeof(TaskScheduler));
    scheduler->count = 0;
    return scheduler;
}

int add_task(TaskScheduler *scheduler, char *name, int duration, int time_slice) {
    if (scheduler->count >= MAX_TASKS) {
        fprintf(stderr, "Error: Task limit reached.\n");
        return -1;
    }
    Task *task = malloc(sizeof(Task));
    strncpy(task->name, name, TASK_NAME_LENGTH);
    task->duration = duration;
    task->time_slice = time_slice;
    task->elapsed_time = 0;
    scheduler->tasks[scheduler->count++] = task;
    return 0;
}

void execute_task(Task *task) {
    int time_to_run = task->time_slice;
    if (task->elapsed_time + time_to_run > task->duration) {
        time_to_run = task->duration - task->elapsed_time;
    }

    printf("Executing task: %s for %d seconds...\n", task->name, time_to_run);
    sleep(time_to_run);
    task->elapsed_time += time_to_run;

    if (task->elapsed_time >= task->duration) {
        printf("Task %s completed.\n", task->name);
    } else {
        printf("Task %s paused (time left: %d seconds).\n", task->name, task->duration - task->elapsed_time);
    }
}

void run_scheduler(TaskScheduler *scheduler) {
    while (scheduler->count > 0) {
        for (int i = 0; i < scheduler->count; i++) {
            execute_task(scheduler->tasks[i]);
            if (scheduler->tasks[i]->elapsed_time >= scheduler->tasks[i]->duration) {
                free(scheduler->tasks[i]); 
                scheduler->tasks[i] = NULL; 
            }
        }

        // Remove completed tasks
        for (int i = 0; i < scheduler->count; i++) {
            if (scheduler->tasks[i] == NULL) {
                for (int j = i; j < scheduler->count - 1; j++) {
                    scheduler->tasks[j] = scheduler->tasks[j + 1];
                }
                scheduler->tasks[--scheduler->count] = NULL;
                i--; // Decrement i to check the new task in the same position
            }
        }
    }
}

void free_scheduler(TaskScheduler *scheduler) {
    for (int i = 0; i < scheduler->count; i++) {
        free(scheduler->tasks[i]);
    }
    free(scheduler);
}

int main() {
    TaskScheduler *scheduler = create_scheduler();

    add_task(scheduler, "Task 1", 5, 2);
    add_task(scheduler, "Task 2", 3, 1);
    add_task(scheduler, "Task 3", 8, 3);

    run_scheduler(scheduler);
    free_scheduler(scheduler);

    return 0;
}