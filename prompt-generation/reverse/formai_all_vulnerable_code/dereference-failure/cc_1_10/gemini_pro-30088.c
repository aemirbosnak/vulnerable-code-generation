//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 8

// Thread data structure
typedef struct {
    int id;                 // Thread ID
    char *command;          // Command to execute
} thread_data_t;

// Thread function
void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Execute the command
    system(data->command);

    // Free the allocated memory
    free(data->command);

    // Return NULL
    return NULL;
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is valid
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command1> <command2> ... <commandN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create the thread pool
    pthread_t threads[MAX_THREADS];

    // Create the thread data structures
    thread_data_t data[MAX_THREADS];

    // Initialize the thread data structures
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].command = strdup(argv[i + 1]);
    }

    // Create the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the allocated memory
    for (int i = 0; i < MAX_THREADS; i++) {
        free(data[i].command);
    }

    // Return success
    return EXIT_SUCCESS;
}