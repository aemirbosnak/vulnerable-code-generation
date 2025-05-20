//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

void fill_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr1, *arr2;
    double start_time, end_time;
    int i;

    // Allocate memory for arrays
    arr1 = (int *) malloc(SIZE * sizeof(int));
    arr2 = (int *) malloc(SIZE * sizeof(int));

    // Fill arrays with random numbers
    fill_array(arr1, SIZE);
    fill_array(arr2, SIZE);

    // Print original arrays
    printf("Original arrays:\n");
    print_array(arr1, SIZE);
    print_array(arr2, SIZE);

    // Sort first array
    start_time = clock();
    for (i = 0; i < SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr1[j] < arr1[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr1[i];
        arr1[i] = arr1[min_idx];
        arr1[min_idx] = temp;
    }
    end_time = clock();
    printf("Sorted first array in %.2f seconds.\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    // Copy sorted array to second array
    start_time = clock();
    for (i = 0; i < SIZE; i++) {
        arr2[i] = arr1[i];
    }
    end_time = clock();
    printf("Copied sorted array in %.2f seconds.\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    // Print sorted arrays
    printf("Sorted arrays:\n");
    print_array(arr1, SIZE);
    print_array(arr2, SIZE);

    // Free memory
    free(arr1);
    free(arr2);

    return 0;
}