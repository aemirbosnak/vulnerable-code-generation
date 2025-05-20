//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

// Thread data structure
typedef struct thread_data {
    int thread_id;
    int *count;
} thread_data_t;

// Thread function
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int i;

    // Increment the count in a loop
    for (i = 0; i < 1000000; i++) {
        (*data->count)++;
    }

    // Print the thread ID and the count
    printf("Thread %d: %d\n", data->thread_id, *data->count);

    // Free the thread data structure
    free(data);

    return NULL;
}

int main() {
    int count = 0;
    pthread_t threads[NUM_THREADS];
    int i;

    // Create the threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->thread_id = i;
        data->count = &count;
        pthread_create(&threads[i], NULL, thread_function, data);
    }

    // Join the threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final count
    printf("Final count: %d\n", count);

    return 0;
}