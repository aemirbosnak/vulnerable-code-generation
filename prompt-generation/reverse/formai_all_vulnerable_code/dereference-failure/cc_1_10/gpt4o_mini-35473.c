//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 100
#define NUM_THREADS 4

// Struct to pass data to threads
typedef struct {
    int *array;
    int start;
    int end;
    long sum;
} ThreadData;

// Function to calculate the sum of squares in a portion of the array
void* calculate_sum_of_squares(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    long sum = 0;

    for (int i = data->start; i < data->end; i++) {
        sum += data->array[i] * data->array[i];
    }

    data->sum = sum;
    return NULL;
}

int main() {
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    long total_sum = 0;

    // Initialize the array with sample values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1; // Fill with numbers from 1 to 100
    }

    // Calculate the size of each partition
    int partition_size = ARRAY_SIZE / NUM_THREADS;

    // Create threads to calculate sum of squares
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].array = array;
        threadData[i].start = i * partition_size;
        // Ensure the last thread handles any remaining elements
        threadData[i].end = (i == NUM_THREADS - 1) ? ARRAY_SIZE : (i + 1) * partition_size;

        pthread_create(&threads[i], NULL, calculate_sum_of_squares, (void*)&threadData[i]);
    }

    // Join threads and accumulate the results
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += threadData[i].sum;
    }

    // Print the result
    printf("The sum of squares from 1 to %d is: %ld\n", ARRAY_SIZE, total_sum);

    // Clean up
    free(array);
    return 0;
}