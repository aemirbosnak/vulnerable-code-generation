//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int i, j;
    clock_t start, end;
    double cpu_time_used;

    int* array1 = (int*) malloc(ARRAY_SIZE * sizeof(int));
    int* array2 = (int*) malloc(ARRAY_SIZE * sizeof(int));
    int* result = (int*) malloc(ARRAY_SIZE * sizeof(int));

    // Initialize array1 with random values
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array1[i] = rand();
    }

    // Initialize array2 with zeros
    for (i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = 0;
    }

    // Benchmark array addition with a for loop
    start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        result[i] = array1[i] + array2[i];
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("For loop benchmark took %f seconds\n", cpu_time_used);

    // Reset array2 to zeros
    for (i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = 0;
    }

    // Benchmark array addition with pointer arithmetic
    start = clock();
    int* p1 = array1;
    int* p2 = array2;
    int* pr = result;
    for (i = 0; i < ARRAY_SIZE; i++) {
        *pr++ = *p1++ + *p2++;
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Pointer arithmetic benchmark took %f seconds\n", cpu_time_used);

    free(array1);
    free(array2);
    free(result);

    return 0;
}