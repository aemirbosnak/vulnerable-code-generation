//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1000000
#define ARRAY_SIZE 1000000

int main()
{
    int i, j;
    int *array;
    clock_t start, end;
    double cpu_time_used;

    // Initialize the array with random values
    array = (int *) malloc(ARRAY_SIZE * sizeof(int));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Warm up the CPU
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            array[i] += array[j];
        }
    }

    // Measure the time for the first function
    start = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            array[j] += array[i];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Measure the time for the second function
    start = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            array[j] += array[i] * 2;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("Time taken for first function: %f seconds\n", cpu_time_used);
    printf("Time taken for second function: %f seconds\n", cpu_time_used);

    return 0;
}