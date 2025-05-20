//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1024
#define LOOP 1000000

int main() {
    int i, j;
    unsigned int *arr, *arr2, *arr3;
    unsigned int sum = 0, sum2 = 0, sum3 = 0;
    clock_t start, end;

    // Allocate memory for arrays
    arr = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
    arr2 = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
    arr3 = (unsigned int *)malloc(SIZE * sizeof(unsigned int));

    // Initialize arrays with random values
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        arr2[i] = rand() % 10;
    }

    // Bitwise OR operation
    start = clock();
    for (i = 0; i < LOOP; i++) {
        for (j = 0; j < SIZE; j++) {
            sum |= arr[j];
        }
    }
    end = clock();
    printf("Bitwise OR operation took %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Bitwise AND operation
    start = clock();
    for (i = 0; i < LOOP; i++) {
        for (j = 0; j < SIZE; j++) {
            sum2 &= arr2[j];
        }
    }
    end = clock();
    printf("Bitwise AND operation took %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Bitwise XOR operation
    start = clock();
    for (i = 0; i < LOOP; i++) {
        for (j = 0; j < SIZE; j++) {
            sum3 ^= arr3[j];
        }
    }
    end = clock();
    printf("Bitwise XOR operation took %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free memory
    free(arr);
    free(arr2);
    free(arr3);

    return 0;
}