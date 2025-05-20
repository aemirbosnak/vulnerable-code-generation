//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_TASKS 10

void *task_thread_function(void *arg) {
    int task_id = (int)arg;
    printf("Task %d started at %d\n", task_id, pthread_self());

    // Simulating task execution time
    sleep(task_id + 1);

    printf("Task %d completed at %d\n", task_id, pthread_self());
    return NULL;
}

void *task_scheduler_function(void *arg) {
    int num_tasks = (int)arg;
    int *tasks = (int *)malloc(num_tasks * sizeof(int));
    pthread_t threads[NUM_THREADS];
    int task_count = 0;

    // Generating random task IDs
    for (int i = 0; i < num_tasks; i++) {
        tasks[i] = rand() % MAX_TASKS;
        task_count++;
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_thread_function, (void *)tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    free(tasks);

    printf("Task scheduler completed.\n");
    return NULL;
}

int main() {
    int num_tasks = 10;
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, task_scheduler_function, (void *)num_tasks);
    pthread_join(scheduler_thread, NULL);

    return 0;
}