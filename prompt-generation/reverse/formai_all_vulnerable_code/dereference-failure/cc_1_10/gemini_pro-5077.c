//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

#define NUM_TASKS 3

typedef struct {
    void (*task)(void*);
    void *arg;
} task_t;

void task1(void *arg) {
    printf("Task 1: Starting...\n");
    sleep(2);
    printf("Task 1: Finished!\n");
}

void task2(void *arg) {
    printf("Task 2: Starting...\n");
    sleep(1);
    printf("Task 2: Finished!\n");
}

void task3(void *arg) {
    printf("Task 3: Starting...\n");
    sleep(3);
    printf("Task 3: Finished!\n");
}

void* scheduler(void *arg) {
    task_t *tasks = (task_t*)arg;
    int i;

    for (i = 0; i < NUM_TASKS; i++) {
        tasks[i].task(tasks[i].arg);
    }

    printf("Scheduler: Finished!\n");

    return NULL;
}

int main(int argc, char **argv) {
    pthread_t tid;
    task_t tasks[NUM_TASKS];
    int status;

    tasks[0].task = task1;
    tasks[0].arg = NULL;
    tasks[1].task = task2;
    tasks[1].arg = NULL;
    tasks[2].task = task3;
    tasks[2].arg = NULL;

    if (pthread_create(&tid, NULL, scheduler, tasks)) {
        perror("pthread_create");
        exit(1);
    }

    if (pthread_join(tid, (void**)&status)) {
        perror("pthread_join");
        exit(1);
    }

    return 0;
}