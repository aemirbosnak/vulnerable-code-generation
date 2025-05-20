//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TASK_COUNT 5

typedef struct Task {
    int id;
    int priority;
    int delay_sec;
} Task;

void* task_handler(void* arg) {
    Task* task = (Task*) arg;
    sleep(task->delay_sec);
    printf("Task %d with priority %d has completed.\n", task->id, task->priority);
    free(task);
    return NULL;
}

int compare_tasks(const void* a, const void* b) {
    Task* task1 = *(Task**) a;
    Task* task2 = *(Task**) b;
    return task2->priority - task1->priority;
}

int main() {
    pthread_t threads[TASK_COUNT];
    Task* tasks[TASK_COUNT];
    int i;

    for (i = 0; i < TASK_COUNT; i++) {
        Task* task = (Task*) malloc(sizeof(Task));
        task->id = i + 1;
        task->priority = rand() % 10 + 1;
        task->delay_sec = rand() % 5 + 1;
        tasks[i] = task;
    }

    printf("Tasks are being scheduled...\n");

    for (i = 0; i < TASK_COUNT; i++) {
        pthread_create(&threads[i], NULL, task_handler, tasks[i]);
    }

    for (i = 0; i < TASK_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All tasks have completed.\n");

    return 0;
}