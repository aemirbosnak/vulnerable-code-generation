//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

// Shared data structure
int shared_array[ARRAY_SIZE];

// Mutex to protect shared data structure
pthread_mutex_t mutex;

// Thread function
void *thread_func(void *arg) {
    int *id = (int *)arg;

    // Acquire mutex lock
    pthread_mutex_lock(&mutex);

    // Do some work on shared data structure
    for (int i = 0; i < ARRAY_SIZE; i++) {
        shared_array[i] += *id;
    }

    // Release mutex lock
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)&i);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    // Check if shared data structure is consistent
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += shared_array[i];
    }
    if (sum != NUM_THREADS * (NUM_THREADS - 1) / 2) {
        printf("Shared data structure is inconsistent!\n");
    } else {
        printf("Shared data structure is consistent.\n");
    }

    return 0;
}