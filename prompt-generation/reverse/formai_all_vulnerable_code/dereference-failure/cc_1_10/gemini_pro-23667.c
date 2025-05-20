//GEMINI-pro DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// A simple structure to hold data for each thread
typedef struct thread_data {
    int tid;
    int *array;
    int array_size;
} thread_data;

// The thread function
void *thread_func(void *arg) {
    // Get the data structure passed to the thread
    thread_data *data = (thread_data *)arg;

    // Print the thread ID
    printf("Thread %d started\n", data->tid);

    // Iterate over the array and print the values
    for (int i = 0; i < data->array_size; i++) {
        printf("Thread %d: array[%d] = %d\n", data->tid, i, data->array[i]);
    }

    // Exit the thread and return NULL
    pthread_exit(NULL);
}

int main() {
    // Create an array of integers
    int array[] = {1, 2, 3, 4, 5};
    int array_size = sizeof(array) / sizeof(int);

    // Create a thread pool
    pthread_t threads[5];

    // Create and start 5 threads
    for (int i = 0; i < 5; i++) {
        // Create a data structure for the thread
        thread_data *data = (thread_data *)malloc(sizeof(thread_data));
        data->tid = i;
        data->array = array;
        data->array_size = array_size;

        // Create the thread
        pthread_create(&threads[i], NULL, thread_func, (void *)data);
    }

    // Join all the threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Exit the program
    return 0;
}