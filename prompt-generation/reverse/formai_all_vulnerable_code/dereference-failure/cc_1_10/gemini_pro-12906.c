//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

typedef struct {
    int time;
    void (*task)();
} Task;

Task tasks[SIZE];

int running = 0;

void run_tasks() {
    while (running) {
        for (int i = 0; i < SIZE; i++) {
            if (tasks[i].time == 0) {
                tasks[i].task();
                tasks[i].time = -1;
            } else if (tasks[i].time > 0) {
                tasks[i].time--;
            }
        }
        sleep(1);
    }
}

void add_task(int time, void (*task)()) {
    for (int i = 0; i < SIZE; i++) {
        if (tasks[i].time == -1) {
            tasks[i].time = time;
            tasks[i].task = task;
            return;
        }
    }
}

void remove_task(void (*task)()) {
    for (int i = 0; i < SIZE; i++) {
        if (tasks[i].task == task) {
            tasks[i].time = -1;
            tasks[i].task = NULL;
            return;
        }
    }
}

void task1() {
    printf("Task 1 running\n");
}

void task2() {
    printf("Task 2 running\n");
}

int main() {
    add_task(5, task1);
    add_task(10, task2);

    running = 1;
    run_tasks();

    return 0;
}