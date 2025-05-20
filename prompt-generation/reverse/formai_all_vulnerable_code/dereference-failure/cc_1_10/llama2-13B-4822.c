//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5
#define TASK_DELAY 5000

struct task {
    int pid;
    int delay;
    void (*function)(void);
};

int main() {
    struct task tasks[MAX_TASKS];
    int i, j;

    // Initialize tasks
    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].pid = -1;
        tasks[i].delay = TASK_DELAY;
        tasks[i].function = NULL;
    }

    // Add tasks
    tasks[0].pid = fork();
    tasks[1].pid = fork();
    tasks[2].pid = fork();
    tasks[3].pid = fork();
    tasks[4].pid = fork();

    // Schedule tasks
    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].pid == 0) {
            // Child process
            tasks[i].function();
            exit(0);
        } else {
            // Parent process
            sleep(tasks[i].delay);
            tasks[i].delay += TASK_DELAY;
        }
    }

    // Wait for all tasks to complete
    for (i = 0; i < MAX_TASKS; i++) {
        wait(NULL);
    }

    return 0;
}

void task1(void) {
    printf("Task 1 running...\n");
    sleep(TASK_DELAY);
    printf("Task 1 completed.\n");
}

void task2(void) {
    printf("Task 2 running...\n");
    sleep(TASK_DELAY * 2);
    printf("Task 2 completed.\n");
}

void task3(void) {
    printf("Task 3 running...\n");
    sleep(TASK_DELAY * 3);
    printf("Task 3 completed.\n");
}

void task4(void) {
    printf("Task 4 running...\n");
    sleep(TASK_DELAY * 4);
    printf("Task 4 completed.\n");
}

void task5(void) {
    printf("Task 5 running...\n");
    sleep(TASK_DELAY * 5);
    printf("Task 5 completed.\n");
}