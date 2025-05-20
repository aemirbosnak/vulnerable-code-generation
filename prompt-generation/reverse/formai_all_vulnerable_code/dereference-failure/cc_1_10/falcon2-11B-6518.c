//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_TASKS 5
#define TASK_DURATION 10

void* task_one() {
    printf("Task 1 running\n");
    sleep(TASK_DURATION);
    printf("Task 1 finished\n");
}

void* task_two() {
    printf("Task 2 running\n");
    sleep(TASK_DURATION);
    printf("Task 2 finished\n");
}

void* task_three() {
    printf("Task 3 running\n");
    sleep(TASK_DURATION);
    printf("Task 3 finished\n");
}

void* task_four() {
    printf("Task 4 running\n");
    sleep(TASK_DURATION);
    printf("Task 4 finished\n");
}

void* task_five() {
    printf("Task 5 running\n");
    sleep(TASK_DURATION);
    printf("Task 5 finished\n");
}

void task_scheduler() {
    pthread_t threads[NUM_TASKS];
    srand(time(NULL));
    int thread_id = 0;

    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_create(&threads[i], NULL, task_one, NULL);
        pthread_create(&threads[i + 1], NULL, task_two, NULL);
        pthread_create(&threads[i + 2], NULL, task_three, NULL);
        pthread_create(&threads[i + 3], NULL, task_four, NULL);
        pthread_create(&threads[i + 4], NULL, task_five, NULL);
    }

    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    task_scheduler();
    return 0;
}