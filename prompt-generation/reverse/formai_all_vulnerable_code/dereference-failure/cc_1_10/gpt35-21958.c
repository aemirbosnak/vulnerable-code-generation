//FormAI DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT 10000000 // Maximum number of integers to generate
#define MAX_ARRAYS 10000 // Maximum number of arrays to generate

// Function to initialize an array with random integers
void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_INT;
    }
}

// Function to sort an array using insertion sort algorithm
void insertionSort(int* arr, int size) {
    int i, j, num;
    for (i = 1; i < size; i++) {
        num = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = num;
    }
}

int main() {
    int* arrays[MAX_ARRAYS];
    int sizes[MAX_ARRAYS];
    clock_t start, end;
    double cpu_time_used;
    int num_arrays;

    srand(time(NULL)); // Seed the random number generator

    // Generate random arrays of integers
    num_arrays = rand() % MAX_ARRAYS + 1;
    printf("Generating %d arrays of random integers...\n", num_arrays);
    for (int i = 0; i < num_arrays; i++) {
        sizes[i] = rand() % MAX_INT + 1;
        arrays[i] = (int*) malloc(sizes[i] * sizeof(int));
        initializeArray(arrays[i], sizes[i]);
    }

    // Sort the arrays using insertion sort algorithm and measure time taken
    printf("Sorting the arrays...\n");
    start = clock();
    for (int i = 0; i < num_arrays; i++) {
        insertionSort(arrays[i], sizes[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting complete! Time taken: %f seconds\n", cpu_time_used);

    // Free memory allocated for arrays
    for (int i = 0; i < num_arrays; i++) {
        free(arrays[i]);
    }

    return 0;
}