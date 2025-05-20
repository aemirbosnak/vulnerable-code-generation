//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TASKS 5
#define MAX_LOAD 100

typedef struct {
    int task_id;
    int load;
} Task;

void *optimize_task(void *arg) {
    Task *task = (Task *)arg;
    printf("Starting task %d with load %d...\n", task->task_id, task->load);
    
    // Simulate optimization work with sleep
    int duration = rand() % 5 + 1;  // Random duration between 1 and 5 seconds
    sleep(duration);
    
    printf("Task %d completed in %d seconds.\n", task->task_id, duration);
    free(task);
    return NULL;
}

void create_tasks(pthread_t *threads) {
    for (int i = 0; i < NUM_TASKS; i++) {
        Task *task = malloc(sizeof(Task));
        task->task_id = i + 1;
        task->load = rand() % MAX_LOAD + 1; // Random load between 1 and 100
        
        int err = pthread_create(&threads[i], NULL, optimize_task, (void *)task);
        if (err != 0) {
            perror("Failed to create thread");
            free(task);
        }
    }
}

void wait_for_completion(pthread_t *threads) {
    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    pthread_t threads[NUM_TASKS];
    
    printf("System Boot Optimizer\n");
    printf("=======================\n");
    
    // Seed random number generator for load
    srand(time(NULL));
    
    create_tasks(threads);
    wait_for_completion(threads);
    
    printf("All boot optimization tasks completed!\n");

    return 0;
}