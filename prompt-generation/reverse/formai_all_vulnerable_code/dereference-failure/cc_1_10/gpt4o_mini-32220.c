//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TASKS 5
#define MAX_RETRY 3

typedef struct {
    int task_id;
    int retry_count;
} Task;

void* execute_task(void* arg) {
    Task *task = (Task*)arg;

    // Simulate some work with a random chance of failure
    while (task->retry_count < MAX_RETRY) {
        printf("Task %d: Attempt %d\n", task->task_id, task->retry_count + 1);

        // Simulate random failure
        int random_failure = rand() % 2;
        if (random_failure == 0) {
            printf("Task %d: Completed Successfully!\n", task->task_id);
            free(task);
            return NULL;
        } else {
            printf("Task %d: Failed! Retrying...\n", task->task_id);
            task->retry_count++;
            sleep(1); // Wait a bit before retrying
        }
    }
    
    printf("Task %d: Max retries reached. Exiting with failure.\n", task->task_id);
    free(task);
    return NULL;
}

void handle_errors(pthread_t* threads, int count) {
    for (int i = 0; i < count; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL)); // Seed the random number generator

    pthread_t threads[NUM_TASKS];

    for (int i = 0; i < NUM_TASKS; i++) {
        Task *task = (Task*)malloc(sizeof(Task));
        task->task_id = i + 1;
        task->retry_count = 0;

        if (pthread_create(&threads[i], NULL, execute_task, (void*)task) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(task);
            handle_errors(threads, i);
            exit(EXIT_FAILURE);
        }
    }

    handle_errors(threads, NUM_TASKS);

    printf("All tasks completed.\n");
    
    return 0;
}