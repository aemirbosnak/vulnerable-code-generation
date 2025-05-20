//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 20

struct task {
    char name[TASK_NAME_LEN];
    int priority;
    void (*function)(void);
};

struct schedule {
    int current_time;
    struct task tasks[MAX_TASKS];
};

void init_schedule(struct schedule *schedule) {
    schedule->current_time = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        schedule->tasks[i].name[0] = '\0';
        schedule->tasks[i].priority = i % 2 == 0 ? 5 : 10;
        schedule->tasks[i].function = NULL;
    }
}

void add_task(struct schedule *schedule, const char *name, int priority, void (*function)(void)) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (strcmp(schedule->tasks[i].name, name) == 0) {
            schedule->tasks[i].priority = priority;
            schedule->tasks[i].function = function;
            return;
        }
    }
    printf("Task %s already exists\n", name);
}

void run_schedule(struct schedule *schedule) {
    while (1) {
        schedule->current_time += 1;
        for (int i = 0; i < MAX_TASKS; i++) {
            if (schedule->tasks[i].priority == schedule->current_time % 10) {
                schedule->tasks[i].function();
                break;
            }
        }
        if (schedule->current_time % 60 == 0) {
            printf("Current time: %d\n", schedule->current_time);
        }
    }
}

int main() {
    struct schedule schedule;
    init_schedule(&schedule);

    add_task(&schedule, "Task 1", 5, printf("Task 1 running\n"));
    add_task(&schedule, "Task 2", 10, printf("Task 2 running\n"));
    add_task(&schedule, "Task 3", 5, printf("Task 3 running\n"));

    run_schedule(&schedule);

    return 0;
}