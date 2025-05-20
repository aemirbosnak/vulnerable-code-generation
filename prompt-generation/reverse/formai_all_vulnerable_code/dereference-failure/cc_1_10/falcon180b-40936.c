//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the thread data structure
typedef struct {
    int id;
    int *result;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
    thread_data_t *data = arg;
    int id = data->id;
    int *result = data->result;

    // Do some work here...
    *result = id * 2;

    return NULL;
}

// Define the main function
int main() {
    int num_threads = 5;
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    // Initialize the thread data
    for (int i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].result = malloc(sizeof(int));
        *data[i].result = 0;
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        int rc = pthread_create(&threads[i], NULL, thread_function, &data[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    // Print the results
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d result: %d\n", i + 1, *data[i].result);
    }

    // Free the memory
    for (int i = 0; i < num_threads; i++) {
        free(data[i].result);
    }

    return 0;
}