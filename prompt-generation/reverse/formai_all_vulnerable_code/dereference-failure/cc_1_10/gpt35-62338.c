//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_LOOPS 1000

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int* array = (int*)malloc(ARRAY_SIZE * sizeof(int));

    // Initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Measure time taken for loop 1
    start = clock();
    for (int i = 0; i < NUM_LOOPS; i++) {
        int sum = 0;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            sum += array[j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for loop 1: %f seconds\n", cpu_time_used);

    // Measure time taken for loop 2
    start = clock();
    for (int i = 0; i < NUM_LOOPS; i++) {
        int sum = 0;
        for (int* p = array; p < array + ARRAY_SIZE; p++) {
            sum += *p;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for loop 2: %f seconds\n", cpu_time_used);

    // Measure time taken for loop 3
    start = clock();
    for (int i = 0; i < NUM_LOOPS; i++) {
        int sum = 0;
        int* p = array;
        int* end = array + ARRAY_SIZE;
        while (p < end) {
            sum += *p++;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for loop 3: %f seconds\n", cpu_time_used);

    free(array);
    return 0;
}