//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_DELAY 300

typedef struct task {
    char *name;
    int delay;
} task_t;

typedef struct schedule {
    task_t tasks[MAX_TASKS];
    int head, tail;
} schedule_t;

void add_task(schedule_t *schedule, char *name, int delay) {
    task_t *task = (task_t *)malloc(sizeof(task_t));
    task->name = name;
    task->delay = delay;

    if (schedule->head == MAX_TASKS) {
        printf("Error: Maximum number of tasks reached\n");
        return;
    }

    schedule->tasks[schedule->head] = *task;
    schedule->head++;
}

void remove_task(schedule_t *schedule, char *name) {
    int i;

    for (i = 0; i < schedule->head; i++) {
        if (strcmp(schedule->tasks[i].name, name) == 0) {
            break;
        }
    }

    if (i == schedule->head) {
        printf("Error: Task not found\n");
        return;
    }

    schedule->tasks[i] = schedule->tasks[schedule->head - 1];
    schedule->head--;
}

void run_schedule(schedule_t *schedule) {
    int i;

    for (i = 0; i < schedule->head; i++) {
        printf("Running task %s with delay %d\n", schedule->tasks[i].name, schedule->tasks[i].delay);
        sleep(schedule->tasks[i].delay);
    }
}

int main() {
    schedule_t schedule;

    add_task(&schedule, "Task 1", 100);
    add_task(&schedule, "Task 2", 200);
    add_task(&schedule, "Task 3", 300);

    run_schedule(&schedule);

    return 0;
}