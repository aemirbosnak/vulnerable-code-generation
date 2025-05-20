//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// Structure for passing data to threads
typedef struct {
    int id;
    int *result;
} thread_data;

// Function to be executed by each thread
void *sum_squares(void *arg) {
    thread_data *data = (thread_data *) arg;
    int result = 0;
    for (int i = 1; i <= data->id; i++) {
        result += i*i;
    }
    *(data->result) = result;
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int results[MAX_THREADS];
    int i;

    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        thread_data data;
        data.id = ids[i];
        data.result = &results[i];
        pthread_create(&threads[i], NULL, sum_squares, &data);
    }

    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("Results:\n");
    for (i = 0; i < MAX_THREADS; i++) {
        printf("Thread %d: %d\n", ids[i], results[i]);
    }

    return 0;
}