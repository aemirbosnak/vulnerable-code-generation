//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

typedef struct Scheduler {
    Task** tasks;
    int size;
} Scheduler;

void initializeScheduler(Scheduler* scheduler) {
    scheduler->tasks = (Task**)malloc(sizeof(Task*) * MAX_SCHEDULER_SIZE);
    scheduler->size = 0;
}

void addTask(Scheduler* scheduler, Task* task) {
    task->next = NULL;
    scheduler->tasks[scheduler->size++] = task;
}

void sortTasks(Scheduler* scheduler) {
    for (int i = 0; i < scheduler->size - 1; i++) {
        for (int j = i + 1; j < scheduler->size; j++) {
            if (scheduler->tasks[i]->priority > scheduler->tasks[j]->priority) {
                Task* temp = scheduler->tasks[i];
                scheduler->tasks[i] = scheduler->tasks[j];
                scheduler->tasks[j] = temp;
            }
        }
    }
}

void executeTasks(Scheduler* scheduler) {
    for (Task* task = scheduler->tasks[0]; task; task = task->next) {
        printf("Executing task: %s\n", task->name);
    }
}

int main() {
    Scheduler scheduler;
    initializeScheduler(&scheduler);

    Task* task1 = (Task*)malloc(sizeof(Task));
    strcpy(task1->name, "Task 1");
    task1->priority = 1;
    addTask(&scheduler, task1);

    Task* task2 = (Task*)malloc(sizeof(Task));
    strcpy(task2->name, "Task 2");
    task2->priority = 3;
    addTask(&scheduler, task2);

    Task* task3 = (Task*)malloc(sizeof(Task));
    strcpy(task3->name, "Task 3");
    task3->priority = 2;
    addTask(&scheduler, task3);

    sortTasks(&scheduler);
    executeTasks(&scheduler);

    return 0;
}