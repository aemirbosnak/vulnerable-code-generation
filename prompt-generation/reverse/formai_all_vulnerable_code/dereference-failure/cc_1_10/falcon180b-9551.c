//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads to be created
#define NUM_THREADS 5

// Define the stack size for each thread
#define STACK_SIZE 1024

// Define the global data shared by all threads
int shared_data = 0;

// Define the data for each thread
struct thread_data {
    int id;
    int value;
};

// Define the function to be executed by each thread
void *thread_function(void *arg) {
    struct thread_data *data = arg;
    int id = data->id;
    int value = data->value;

    // Do some work
    int result = value * 2;

    // Update the shared data
    shared_data += result;

    // Print the result
    printf("Thread %d completed with result: %d\n", id, result);

    return NULL;
}

int main() {
    // Allocate memory for thread data
    struct thread_data *thread_data = malloc(NUM_THREADS * sizeof(struct thread_data));

    // Initialize thread data
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i + 1;
        thread_data[i].value = i * 10;
    }

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final result
    printf("Final result: %d\n", shared_data);

    return 0;
}