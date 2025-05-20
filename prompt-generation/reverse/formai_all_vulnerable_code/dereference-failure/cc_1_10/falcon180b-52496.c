//Falcon-180B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for synchronization
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Flag to indicate if all threads have finished
int finished = 0;

// Function to be executed by each thread
void *thread_func(void *arg) {
    // Lock the mutex before entering critical section
    pthread_mutex_lock(&mutex);

    // Wait for other threads to enter critical section
    pthread_cond_wait(&cond, &mutex);

    // Execute thread-specific task
    int thread_id = *((int *) arg);
    printf("Thread %d executing task...\n", thread_id);

    // Signal other threads to proceed
    finished++;
    pthread_cond_signal(&cond);

    // Unlock the mutex before exiting critical section
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Create an array of thread IDs
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, thread_func, thread_id);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}