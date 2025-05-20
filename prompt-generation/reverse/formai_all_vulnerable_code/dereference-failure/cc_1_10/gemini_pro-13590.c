//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10

typedef struct task {
    char *name;
    int priority;
    int state; // 0 = new, 1 = running, 2 = finished
    void (*func)();
} task;

task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int priority, void (*func)()) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: too many tasks\n");
        return;
    }

    tasks[num_tasks].name = strdup(name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].state = 0;
    tasks[num_tasks].func = func;

    num_tasks++;
}

void run_tasks() {
    int i;

    while (1) {
        // Find the highest priority task that is ready to run
        int highest_priority = -1;
        int highest_priority_index = -1;
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].state == 0 && tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                highest_priority_index = i;
            }
        }

        // If there are no tasks to run, break out of the loop
        if (highest_priority_index == -1) {
            break;
        }

        // Run the highest priority task
        tasks[highest_priority_index].state = 1;
        tasks[highest_priority_index].func();
        tasks[highest_priority_index].state = 2;
    }
}

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

void task3() {
    printf("Task 3 running\n");
}

int main() {
    add_task("Task 1", 1, task1);
    add_task("Task 2", 2, task2);
    add_task("Task 3", 3, task3);

    run_tasks();

    return 0;
}