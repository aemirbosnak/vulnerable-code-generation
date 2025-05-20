//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct task_t {
    int id;
    int interval;
    time_t last_run;
} task_t;

void print_time() {
    time_t now;
    time(&now);
    printf("Current time: %s\n", ctime(&now));
}

void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

task_t * create_task(int id, int interval) {
    task_t * task = malloc(sizeof(task_t));
    task->id = id;
    task->interval = interval;
    task->last_run = 0;
    return task;
}

void destroy_task(task_t * task) {
    free(task);
}

void run_task(task_t * task) {
    printf("Running task %d...\n", task->id);
    time(&task->last_run);
}

int main() {
    task_t * task1 = create_task(1, 5);
    task_t * task2 = create_task(2, 10);

    while (1) {
        print_time();

        if (difftime(time(NULL), task1->last_run) > task1->interval) {
            run_task(task1);
        }

        if (difftime(time(NULL), task2->last_run) > task2->interval) {
            run_task(task2);
        }

        sleep(1);
    }

    destroy_task(task1);
    destroy_task(task2);

    return 0;
}