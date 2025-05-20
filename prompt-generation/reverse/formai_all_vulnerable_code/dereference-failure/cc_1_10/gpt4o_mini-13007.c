//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ARRAY_SIZE 1000000
#define NUM_THREADS 4

typedef struct {
    int *array;
    long start;
    long end;
} ThreadData;

void* accumulate(void *arg) {
    ThreadData *data = (ThreadData*)arg;
    int *array = data->array;
    long start = data->start;
    long end = data->end;

    long long *partial_sum = malloc(sizeof(long long));
    *partial_sum = 0;

    for (long i = start; i < end; i++) {
        *partial_sum += array[i];
    }

    return (void *)partial_sum;
}

long long parallel_sum(int *array, int size) {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    long long total_sum = 0;

    // Determine the workload for each thread
    long chunk_size = size / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].array = array;
        threadData[i].start = i * chunk_size;
        threadData[i].end = (i == NUM_THREADS - 1) ? size : (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, accumulate, &threadData[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        long long *partial_sum;
        pthread_join(threads[i], (void**)&partial_sum);
        total_sum += *partial_sum;
        free(partial_sum);
    }

    return total_sum;
}

int main() {
    // Initialize random number generator
    srand(time(0));

    // Allocate an array with random values
    int *array = malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Measure the performance using a high-resolution timer
    clock_t start_time = clock();

    // Calculate the sum in parallel
    long long total_sum = parallel_sum(array, ARRAY_SIZE);

    clock_t end_time = clock();
    
    // Output the results
    printf("Total Sum: %lld\n", total_sum);
    printf("Time taken: %lf seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    // Clean up resources
    free(array);
    return 0;
}