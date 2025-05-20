//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the size of the pattern
#define PATTERN_SIZE 10

// Define the mutex
pthread_mutex_t mutex;

// Define the condition variable
pthread_cond_t cond;

// Define the thread data structure
typedef struct thread_data {
    int id;
    int start;
    int end;
} thread_data;

// Define the thread function
void *thread_function(void *arg) {
    // Get the thread data
    thread_data *data = (thread_data *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait for the condition variable to be signaled
    pthread_cond_wait(&cond, &mutex);

    // Print the pattern
    for (int i = data->start; i < data->end; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Main function
int main() {
    // Initialize the mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->id = i;
        data->start = i * PATTERN_SIZE / NUM_THREADS;
        data->end = (i + 1) * PATTERN_SIZE / NUM_THREADS;
        pthread_create(&threads[i], NULL, thread_function, data);
    }

    // Signal the condition variable
    pthread_cond_signal(&cond);

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}