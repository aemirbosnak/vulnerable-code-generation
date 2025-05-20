//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure of the thread's data
typedef struct {
    int id;
    int *result;
} thread_data_t;

// Function that will be executed by each thread
void *thread_function(void *data) {
    thread_data_t *thread_data = (thread_data_t *) data;
    int id = thread_data->id;
    int *result = thread_data->result;

    // Do some heavy computation here
    int sum = 0;
    for (int i = 0; i < 100000000; i++) {
        sum += i;
    }

    // Store the result in the shared result variable
    *result = sum;

    printf("Thread %d finished with result %d\n", id, sum);
    return NULL;
}

int main() {
    int num_threads = 4;
    pthread_t threads[num_threads];
    int results[num_threads];

    // Initialize the result array
    for (int i = 0; i < num_threads; i++) {
        results[i] = 0;
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        thread_data_t *thread_data = (thread_data_t *) malloc(sizeof(thread_data_t));
        thread_data->id = i;
        thread_data->result = &results[i];
        pthread_create(&threads[i], NULL, thread_function, thread_data);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d result: %d\n", i, results[i]);
    }

    return 0;
}