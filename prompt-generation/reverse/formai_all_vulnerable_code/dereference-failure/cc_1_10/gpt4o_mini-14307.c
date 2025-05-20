//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4
#define MAX_NUM 10000

// Structure to hold parameters for each thread
typedef struct {
    int thread_id;
    int start_index;
    int end_index;
    double* results;
} ThreadData;

// Function to calculate the square root of numbers in a given range
void* calculate_sqrt(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    for (int i = data->start_index; i < data->end_index; i++) {
        data->results[i] = sqrt(i);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    double* results = malloc(sizeof(double) * MAX_NUM);
    int rc;
    int range = MAX_NUM / NUM_THREADS;

    // Create threads for square root calculation
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].start_index = i * range;
        thread_data[i].end_index = (i + 1) * range;
        thread_data[i].results = results;

        rc = pthread_create(&threads[i], NULL, calculate_sqrt, (void*)&thread_data[i]);
        if (rc) {
            printf("Error: Unable to create thread %d, %d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Join threads to the main thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    printf("Square roots from 0 to %d:\n", MAX_NUM - 1);
    for (int i = 0; i < MAX_NUM; i++) {
        printf("sqrt(%d) = %.2f\n", i, results[i]);
    }

    // Free allocated memory
    free(results);

    pthread_exit(NULL);
}