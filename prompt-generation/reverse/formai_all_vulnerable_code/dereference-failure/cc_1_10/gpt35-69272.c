//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linear_search(int *array, int n, int key)
{
    int i;
    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found in the array\n");
}

void binary_search(int *array, int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == key) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (array[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not found in the array\n");
}

int main()
{
    int n = 1000000, key = 123456, i, *array;
    clock_t tic, toc;
    double linear_time, binary_time;

    // Allocate memory for array
    array = (int*)malloc(n * sizeof(int));

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        array[i] = rand() % n;
    }

    // Benchmarking linear search
    printf("Benchmarking linear search... ");
    tic = clock();
    linear_search(array, n, key);
    toc = clock();
    linear_time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", linear_time);

    // Benchmarking binary search
    printf("Benchmarking binary search... ");
    tic = clock();
    binary_search(array, n, key);
    toc = clock();
    binary_time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", binary_time);

    // Free array memory
    free(array);

    return 0;
}