//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_SCHEDulers 5

typedef struct Scheduler {
    char name[20];
    int tasks_left;
    struct Task **tasks;
} Scheduler;

typedef struct Task {
    char name[20];
    int duration;
    struct Scheduler *scheduler;
} Task;

void add_task(Scheduler *scheduler, Task *task) {
    task->scheduler = scheduler;
    scheduler->tasks_left++;
    scheduler->tasks = realloc(scheduler->tasks, (scheduler->tasks_left) * sizeof(struct Task));
    scheduler->tasks[scheduler->tasks_left - 1] = task;
}

void run_scheduler(Scheduler *scheduler) {
    for (int i = 0; i < scheduler->tasks_left; i++) {
        Task *task = scheduler->tasks[i];
        printf("Task: %s, Duration: %d, Scheduler: %s\n", task->name, task->duration, task->scheduler->name);
        sleep(task->duration);
    }
}

int main() {
    Scheduler **schedulers = malloc(NUM_SCHEDulers * sizeof(Scheduler));
    for (int i = 0; i < NUM_SCHEDulers; i++) {
        schedulers[i] = malloc(sizeof(Scheduler));
        strcpy(schedulers[i]->name, "Scheduler ");
        schedulers[i]->tasks_left = 0;
        schedulers[i]->tasks = NULL;
    }

    Task **tasks = malloc(10 * sizeof(Task));
    for (int i = 0; i < 10; i++) {
        tasks[i] = malloc(sizeof(Task));
        strcpy(tasks[i]->name, "Task ");
        tasks[i]->duration = rand() % 5 + 1;
    }

    for (int i = 0; i < 10; i++) {
        add_task(schedulers[0], tasks[i]);
    }

    for (int i = 0; i < NUM_SCHEDulers; i++) {
        run_scheduler(schedulers[i]);
    }

    return 0;
}