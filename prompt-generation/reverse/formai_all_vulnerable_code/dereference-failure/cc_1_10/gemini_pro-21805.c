//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct TaskObj {
    struct TaskObj* next;
    void (*task)();
    unsigned int delay;
    time_t triggered;
} TaskObj;

TaskObj* task_head = NULL;

void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

void schedule_task(void (*task)(), unsigned int delay) {
    TaskObj* new_task = malloc(sizeof(TaskObj));
    new_task->task = task;
    new_task->delay = delay;
    new_task->triggered = time(NULL) + delay;
    new_task->next = task_head;
    task_head = new_task;
}

void run_tasks() {
    time_t current_time = time(NULL);
    TaskObj* curr_task = task_head;
    while (curr_task) {
        if (curr_task->triggered <= current_time) {
            curr_task->task();
            task_head = curr_task->next;
            free(curr_task);
            curr_task = task_head;
        } else {
            curr_task = curr_task->next;
        }
    }
}

int main() {
    schedule_task(task1, 2);
    schedule_task(task2, 5);

    while (1) {
        run_tasks();
        sleep(1);
    }

    return 0;
}