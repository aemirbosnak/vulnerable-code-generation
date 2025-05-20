//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 20

typedef struct {
    char name[TASK_NAME_LENGTH];
    int priority;
    void (*function)(void);
} task_t;

typedef struct {
    task_t tasks[MAX_TASKS];
    int current_task;
} scheduler_t;

void init_scheduler(scheduler_t *scheduler) {
    int i;

    for (i = 0; i < MAX_TASKS; i++) {
        scheduler->tasks[i].priority = i % 2 == 0 ? 5 : 10;
        strcpy(scheduler->tasks[i].name, "Task");
    }

    scheduler->current_task = 0;
}

void run_scheduler(scheduler_t *scheduler) {
    while (1) {
        if (scheduler->current_task == MAX_TASKS - 1) {
            scheduler->current_task = 0;
        }

        if (scheduler->tasks[scheduler->current_task].priority == 5) {
            printf("Running task: %s\n", scheduler->tasks[scheduler->current_task].name);
            scheduler->tasks[scheduler->current_task].function();
        } else {
            printf("Skipping task: %s (priority %d)\n", scheduler->tasks[scheduler->current_task].name, scheduler->tasks[scheduler->current_task].priority);
        }

        scheduler->current_task++;

        if (scheduler->current_task == MAX_TASKS) {
            scheduler->current_task = 0;
        }

        sleep(1);
    }
}

void task1(void) {
    printf("Task 1 running\n");
    sleep(3);
    printf("Task 1 finished\n");
}

void task2(void) {
    printf("Task 2 running\n");
    sleep(2);
    printf("Task 2 finished\n");
}

int main() {
    scheduler_t scheduler;

    init_scheduler(&scheduler);

    run_scheduler(&scheduler);

    return 0;
}