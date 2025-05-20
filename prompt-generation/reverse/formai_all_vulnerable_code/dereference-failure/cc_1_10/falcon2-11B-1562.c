//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int numThreads = 5;
int numTasks = 10;

struct task {
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int endTime;
};

int compare(const void* a, const void* b) {
    struct task* taskA = (struct task*) a;
    struct task* taskB = (struct task*) b;

    if (taskA->arrivalTime < taskB->arrivalTime) {
        return -1;
    } else if (taskA->arrivalTime > taskB->arrivalTime) {
        return 1;
    } else {
        return 0;
    }
}

void* threadFunction(void* arg) {
    struct task* task = (struct task*) arg;

    sleep(task->burstTime);

    return NULL;
}

int main() {
    struct task* tasks = (struct task*) malloc(numTasks * sizeof(struct task));

    for (int i = 0; i < numTasks; i++) {
        tasks[i].id = i;
        tasks[i].arrivalTime = rand() % 100;
        tasks[i].burstTime = rand() % 100;
    }

    qsort(tasks, numTasks, sizeof(struct task), compare);

    pthread_t threads[numThreads];

    for (int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void*) &tasks[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < numTasks; i++) {
        printf("Task %d arrived at %d and completed at %d\n",
               tasks[i].id, tasks[i].arrivalTime, tasks[i].endTime);
    }

    return 0;
}