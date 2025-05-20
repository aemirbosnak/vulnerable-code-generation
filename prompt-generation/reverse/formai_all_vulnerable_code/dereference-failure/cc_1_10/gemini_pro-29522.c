//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Custom threading library that electrifies your code!

// Structure to hold thread information
typedef struct thread_info {
    int tid;        // Thread ID
    int iterations; // Number of iterations to perform
} thread_info_t;

// Thread function that prints its ID and performs a specified number of iterations
void *thread_function(void *arg) {
    thread_info_t *info = (thread_info_t *)arg;

    printf("Greetings from thread %d, starting %d iterations!\n", info->tid, info->iterations);

    // Perform iterations
    for (int i = 0; i < info->iterations; i++) {
        // Do something exciting...
        printf("Iteration %d, thread %d reporting for duty!\n", i, info->tid);
    }

    printf("Thread %d complete, returning to base!\n", info->tid);

    // Free the thread info structure
    free(info);

    return NULL;
}

int main() {
    // Ignite the threading adventure!

    // Initialize the threading library
    printf("Initializing the threading library... Prepare for liftoff!\n");
    pthread_t threads[4]; // Array to hold thread IDs
    thread_info_t thread_info[4]; // Array to hold thread information

    // Create four energetic threads
    printf("Creating four threads, each with a unique mission!\n");
    for (int i = 0; i < 4; i++) {
        thread_info[i].tid = i + 1;
        thread_info[i].iterations = rand() % 10 + 1; // Random number of iterations (1 to 10)

        // Create the thread
        int err = pthread_create(&threads[i], NULL, thread_function, &thread_info[i]);
        if (err != 0) {
            printf("Thread creation failed! Aborting mission!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Join the threads and wait for them to complete their tasks
    printf("Joining the threads, waiting for them to land safely!\n");
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Mission accomplished!
    printf("All threads have completed their missions successfully. High-five!\n");

    return 0;
}