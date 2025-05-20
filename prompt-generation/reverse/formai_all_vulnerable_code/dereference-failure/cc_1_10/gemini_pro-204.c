//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the maximum number of threads that can be created
#define MAX_THREADS 6

// Define the number of times each thread will print its message
#define NUM_ITERS 20

// Define the message that each thread will print
#define MESSAGE "Hello from thread %d!\n"

// Define the thread function
void *thread_func(void *arg) {
    // Get the thread ID
    int tid = *(int *)arg;

    // Print the thread's message
    for (int i = 0; i < NUM_ITERS; i++) {
        printf(MESSAGE, tid);
    }

    // Return NULL to indicate success
    return NULL;
}

// Main function
int main() {
    // Create an array of thread IDs
    pthread_t tids[MAX_THREADS];

    // Create the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        // Allocate memory for the thread ID
        int *tid = malloc(sizeof(int));
        *tid = i;

        // Create the thread
        if (pthread_create(&tids[i], NULL, thread_func, (void *)tid) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(tids[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    // Free the memory allocated for the thread IDs
    for (int i = 0; i < MAX_THREADS; i++) {
        free(tids[i]);
    }

    return EXIT_SUCCESS;
}