//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int arrival_time;
    int execution_time;
} Task;

typedef struct {
    int current_time;
    int num_tasks;
    Task tasks[MAX_TASKS];
} TaskScheduler;

TaskScheduler* create_task_scheduler(int num_tasks) {
    TaskScheduler* scheduler = malloc(sizeof(TaskScheduler));
    scheduler->current_time = 0;
    scheduler->num_tasks = num_tasks;
    for (int i = 0; i < num_tasks; i++) {
        scheduler->tasks[i].id = i;
        scheduler->tasks[i].arrival_time = rand() % 10;
        scheduler->tasks[i].execution_time = rand() % 5;
    }
    return scheduler;
}

void destroy_task_scheduler(TaskScheduler* scheduler) {
    free(scheduler);
}

void schedule_tasks(TaskScheduler* scheduler) {
    int running_task = -1;
    int next_task = -1;
    while (scheduler->current_time < 100) {
        // Check if there is a task that has arrived and is ready to run
        for (int i = 0; i < scheduler->num_tasks; i++) {
            if (scheduler->tasks[i].arrival_time <= scheduler->current_time && scheduler->tasks[i].execution_time > 0) {
                if (running_task == -1) {
                    running_task = i;
                } else if (scheduler->tasks[i].execution_time < scheduler->tasks[running_task].execution_time) {
                    next_task = i;
                }
            }
        }

        // If there is a task running, execute it
        if (running_task != -1) {
            scheduler->tasks[running_task].execution_time--;
            printf("Task %d is running (execution time remaining: %d)\n", scheduler->tasks[running_task].id, scheduler->tasks[running_task].execution_time);
            if (scheduler->tasks[running_task].execution_time == 0) {
                running_task = -1;
            }
        }

        // If there is a task that is ready to run and has a shorter execution time than the current task, switch to that task
        if (next_task != -1) {
            running_task = next_task;
            next_task = -1;
        }

        scheduler->current_time++;
    }
}

int main() {
    // Create a task scheduler with 10 tasks
    TaskScheduler* scheduler = create_task_scheduler(10);

    // Schedule the tasks
    schedule_tasks(scheduler);

    // Destroy the task scheduler
    destroy_task_scheduler(scheduler);

    return 0;
}