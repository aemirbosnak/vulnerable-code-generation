//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread data structure
typedef struct thread_data {
    int thread_id;
    int num_iterations;
} thread_data_t;

// Thread function
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Perform the specified number of iterations
    for (int i = 0; i < data->num_iterations; i++) {
        printf("Thread %d: Iteration %d\n", data->thread_id, i);
    }

    // Return a pointer to the thread data structure
    return data;
}

// Main function
int main(int argc, char **argv) {
    // Check for the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num_threads> <num_iterations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the number of threads and iterations
    int num_threads = atoi(argv[1]);
    int num_iterations = atoi(argv[2]);

    // Create an array of thread data structures
    thread_data_t *data = malloc(sizeof(thread_data_t) * num_threads);

    // Create an array of thread IDs
    pthread_t *tids = malloc(sizeof(pthread_t) * num_threads);

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        data[i].thread_id = i;
        data[i].num_iterations = num_iterations;
        pthread_create(&tids[i], NULL, thread_function, &data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(tids[i], (void **)&data[i]);
    }

    // Print the thread data
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d: Returned %p\n", data[i].thread_id, data[i]);
    }

    // Free the memory
    free(data);
    free(tids);

    return EXIT_SUCCESS;
}