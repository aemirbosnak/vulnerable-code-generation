//FormAI DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100000 // Maximum number of elements to sort
#define NUM_RUNS 10 // Number of times to run the benchmark

// Function to generate random integers
int rand_int(int max) {
    return rand() % max + 1;
}

// Function to copy an array
void copy_array(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Function to perform selection sort on an array
void selection_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

// Function to perform quick sort on an array
void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int tmp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = tmp;
        int pivot_idx = i + 1;
        quick_sort(arr, left, pivot_idx - 1);
        quick_sort(arr, pivot_idx + 1, right);
    }
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for arrays
    int *arr1 = (int *) malloc(sizeof(int) * MAX_N);
    int *arr2 = (int *) malloc(sizeof(int) * MAX_N);
    int *arr3 = (int *) malloc(sizeof(int) * MAX_N);

    // Generate random arrays
    for (int i = 0; i < MAX_N; i++) {
        arr1[i] = rand_int(MAX_N);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    // Perform selection sort and measure time
    clock_t start = clock();
    selection_sort(arr1, MAX_N);
    clock_t end = clock();
    double selection_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort time: %f seconds\n", selection_sort_time);

    // Perform quick sort and measure time
    start = clock();
    quick_sort(arr2, 0, MAX_N - 1);
    end = clock();
    double quick_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort time: %f seconds\n", quick_sort_time);

    // Perform built-in qsort function and measure time
    start = clock();
    qsort(arr3, MAX_N, sizeof(int), (void *) rand_int);
    end = clock();
    double qsort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("qsort time: %f seconds\n", qsort_time);

    // Free memory
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}