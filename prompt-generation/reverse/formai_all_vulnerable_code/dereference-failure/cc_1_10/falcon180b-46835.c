//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 5

// Define the stack size for each thread
#define STACK_SIZE (1024 * 1024)

// Define the data structure for each thread
typedef struct thread_data {
    int thread_id;
    char *message;
} thread_data_t;

// Define the function for each thread
void *thread_function(void *param) {
    // Get the thread data
    thread_data_t *data = (thread_data_t *) param;

    // Print the message for the thread
    printf("Thread %d: %s\n", data->thread_id, data->message);

    // Exit the thread
    return NULL;
}

// Define the main function
int main() {
    // Allocate memory for the thread data
    thread_data_t *thread_data = (thread_data_t *) malloc(NUM_THREADS * sizeof(thread_data_t));

    // Initialize the thread data
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].message = (char *) malloc(100 * sizeof(char));
        sprintf(thread_data[i].message, "Thread %d", i);
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &thread_data[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the memory
    for (int i = 0; i < NUM_THREADS; i++) {
        free(thread_data[i].message);
    }
    free(thread_data);

    return 0;
}