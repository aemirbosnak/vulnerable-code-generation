//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4

// Shared data
int shared_data = 0;

// Semaphore to protect shared data
sem_t semaphore;

// Thread function
void *thread_func(void *arg) {
    int tid = *(int *)arg;

    // Acquire semaphore
    sem_wait(&semaphore);

    // Critical section: access shared data
    printf("Thread %d: shared_data = %d\n", tid, shared_data);
    shared_data++;

    // Release semaphore
    sem_post(&semaphore);

    return NULL;
}

int main() {
    // Initialize semaphore
    sem_init(&semaphore, 0, 1);

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *tid = malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads[i], NULL, thread_func, (void *)tid);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    // Print final value of shared data
    printf("Final value of shared_data: %d\n", shared_data);
    return 0;
}