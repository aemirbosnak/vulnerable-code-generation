//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int *arr;
    int i;
    clock_t start, end;

    // Allocate memory for array
    arr = (int *) malloc(ARRAY_SIZE * sizeof(int));

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array
    start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        int j;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    end = clock();

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate time taken for sorting
    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %.6f seconds\n", time_taken);

    // Free memory allocated for array
    free(arr);

    return 0;
}