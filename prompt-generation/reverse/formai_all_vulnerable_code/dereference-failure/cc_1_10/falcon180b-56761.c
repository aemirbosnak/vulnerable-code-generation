//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

int main() {
    int i, n;
    float *arr;
    clock_t start, end;

    // Initialize random seed
    srand(time(NULL));

    // Allocate memory for array
    arr = (float *) malloc(SIZE * sizeof(float));

    // Fill array with random numbers in the range [0, 1)
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() / (float) RAND_MAX;
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    // Start timing
    start = clock();

    // Perform bucket sort
    int *bucket = (int *) malloc(SIZE * sizeof(int));
    for (i = 0; i < SIZE; i++) {
        n = (int) (arr[i] * SIZE);
        bucket[n]++;
    }
    for (i = 1; i < SIZE; i++) {
        bucket[i] += bucket[i - 1];
    }
    float *sorted_arr = (float *) malloc(SIZE * sizeof(float));
    for (i = SIZE - 1; i >= 0; i--) {
        sorted_arr[--bucket[i]] = arr[i];
    }
    for (i = 0; i < SIZE; i++) {
        arr[i] = sorted_arr[i];
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    // Stop timing
    end = clock();

    // Calculate and print elapsed time
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %lf seconds\n", elapsed_time);

    // Free memory
    free(arr);
    free(bucket);
    free(sorted_arr);

    return 0;
}