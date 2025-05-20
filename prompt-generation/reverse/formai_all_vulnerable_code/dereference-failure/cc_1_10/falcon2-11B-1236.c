//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

typedef struct {
    int id;
    int priority;
    void (*func)(void*);
    void *arg;
} Task;

int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task*)a;
    Task *task2 = (Task*)b;
    return task1->priority - task2->priority;
}

void* task_runner(void* arg) {
    Task *task = (Task*)arg;
    task->func(task->arg);
    return NULL;
}

void schedule_tasks() {
    srand(time(NULL));
    Task tasks[NUM_THREADS];
    int task_count = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        tasks[i].id = i;
        tasks[i].priority = rand() % 100;
        tasks[i].func = task_runner;
        tasks[i].arg = (void*)i;
        task_count++;
    }

    qsort(tasks, task_count, sizeof(Task), compare_tasks);

    pthread_t threads[NUM_THREADS];
    int thread_id = 0;

    for (int i = 0; i < task_count; i++) {
        pthread_create(&threads[thread_id], NULL, task_runner, (void*)&tasks[i]);
        thread_id++;
    }

    for (int i = 0; i < thread_id; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    schedule_tasks();
    return 0;
}