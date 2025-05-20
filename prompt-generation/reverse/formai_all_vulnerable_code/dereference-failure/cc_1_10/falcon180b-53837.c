//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int i, j;
    double start, end;
    int *arr1, *arr2;

    // Allocate memory for arrays
    arr1 = (int *) malloc(SIZE * sizeof(int));
    arr2 = (int *) malloc(SIZE * sizeof(int));

    // Initialize arrays with random values
    for (i = 0; i < SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    // Start timer
    start = clock();

    // Sort array 1 using quicksort
    for (i = 0; i < SIZE - 1; i++) {
        int pivot = arr1[i];
        int j = i + 1;
        while (j < SIZE) {
            if (arr1[j] < pivot) {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
                j++;
            } else {
                j++;
            }
        }
    }

    // Sort array 2 using mergesort
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr2[i] > arr2[j]) {
                int temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }

    // End timer
    end = clock();

    // Print results
    printf("Quicksort time: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);
    printf("Merge sort time: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Free memory
    free(arr1);
    free(arr2);

    return 0;
}