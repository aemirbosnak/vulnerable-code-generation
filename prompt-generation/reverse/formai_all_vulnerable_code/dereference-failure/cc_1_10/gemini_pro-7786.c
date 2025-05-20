//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

// Mutex for protecting shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread-specific data
__thread int thread_num;

// Shared data
int shared_data = 0;

// Function to be executed by each thread
void *thread_func(void *arg) {
    int i;
    thread_num = (int)arg;

    // Acquire the mutex
    pthread_mutex_lock(&mutex);

    // Update the shared data
    for (i = 0; i < 1000000; i++) {
        shared_data++;
    }

    // Release the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char **argv) {
    int num_threads;
    pthread_t *threads;
    int i;

    // Get the number of threads to create
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    num_threads = atoi(argv[1]);

    // Create the threads
    threads = malloc(sizeof(pthread_t) * num_threads);
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    // Join the threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final value of the shared data
    printf("Final value of shared data: %d\n", shared_data);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return EXIT_SUCCESS;
}