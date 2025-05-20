//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000000
#define MAX_ITER 1000

int main() {
    int i, j, k, n;
    double *arr1, *arr2, *arr3, *arr4;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory for arrays
    arr1 = (double *) malloc(MAX_SIZE * sizeof(double));
    arr2 = (double *) malloc(MAX_SIZE * sizeof(double));
    arr3 = (double *) malloc(MAX_SIZE * sizeof(double));
    arr4 = (double *) malloc(MAX_SIZE * sizeof(double));

    // Initialize arrays with random values
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = rand() % 1000;
        arr3[i] = rand() % 1000;
        arr4[i] = rand() % 1000;
    }

    // Perform matrix multiplication
    start = clock();
    for (k = 0; k < MAX_ITER; k++) {
        for (i = 0; i < MAX_SIZE; i++) {
            for (j = 0; j < MAX_SIZE; j++) {
                arr4[i] += arr1[i] * arr2[j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %.2f seconds\n", cpu_time_used);

    // Free memory
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);

    return 0;
}