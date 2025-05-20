//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define thread arguments structure
typedef struct thread_args {
    int id;             // Thread ID
    int iterations;     // Number of iterations
    int sleep_time;     // Sleep time in milliseconds
} thread_args;

// Thread function
void *thread_function(void *args) {
    thread_args *t_args = (thread_args *)args;

    // Print thread information
    printf("Thread %d started with %d iterations and %d ms sleep time.\n",
        t_args->id, t_args->iterations, t_args->sleep_time);

    // Perform iterations
    for (int i = 0; i < t_args->iterations; i++) {
        // Do some work
        printf("Thread %d iteration %d\n", t_args->id, i);

        // Sleep for a while
        usleep(t_args->sleep_time * 1000);
    }

    printf("Thread %d finished.\n", t_args->id);

    // Free thread arguments
    free(t_args);

    return NULL;
}

// Main function
int main() {
    // Get number of threads and iterations from user
    int num_threads, iterations, sleep_time;
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);
    printf("Enter number of iterations: ");
    scanf("%d", &iterations);
    printf("Enter sleep time (in milliseconds): ");
    scanf("%d", &sleep_time);

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        // Allocate memory for thread arguments
        thread_args *t_args = malloc(sizeof(thread_args));
        t_args->id = i;
        t_args->iterations = iterations;
        t_args->sleep_time = sleep_time;

        // Create thread
        pthread_create(&threads[i], NULL, thread_function, t_args);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");

    return 0;
}