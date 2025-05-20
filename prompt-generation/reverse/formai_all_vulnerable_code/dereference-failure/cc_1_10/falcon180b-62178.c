//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define STACK_SIZE 1024 * 8
#define TASK_COUNT 10

// Function to be executed by each thread
void *task_function(void *arg) {
    int task_id = *(int *) arg;
    printf("Thread %d executing task %d\n", task_id, task_id);
    return NULL;
}

// Function to schedule tasks for execution
void schedule_tasks() {
    int i, j;
    for (i = 0; i < NUM_THREADS; i++) {
        for (j = 0; j < TASK_COUNT; j++) {
            pthread_t thread_id;
            int *task_id = malloc(sizeof(int));
            *task_id = j;
            pthread_create(&thread_id, NULL, task_function, task_id);
            printf("Scheduled task %d for thread %d\n", j, i);
        }
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    srand(time(NULL));

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, schedule_tasks, NULL);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
        printf("Created thread %d\n", i);
    }

    // Join with all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join with thread, %d\n", rc);
            exit(-1);
        }
        printf("Joined with thread %d\n", i);
    }

    return 0;
}