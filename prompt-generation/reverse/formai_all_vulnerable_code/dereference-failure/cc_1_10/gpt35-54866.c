//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Comparison function for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to generate an array of random integers
int* generateRandomArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Main function to run benchmarking
int main() {
    // Initialize seed for random number generator
    srand(time(NULL));
    
    // Define array sizes to test
    int sizes[] = {1000, 10000, 100000};
    int numSizes = sizeof(sizes) / sizeof(int);
    
    // Loop through array sizes
    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        
        // Generate random array of given size
        int* arr = generateRandomArray(size);
        
        // Use clock() to measure starting time
        clock_t start = clock();
        
        // Call qsort() to sort array
        qsort(arr, size, sizeof(int), compare);
        
        // Use clock() to measure ending time
        clock_t end = clock();
        
        // Calculate elapsed time and print results
        double timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Sorted %d numbers in %f seconds\n", size, timeElapsed);
        
        // Free memory allocated for array
        free(arr);
    }
    
    return 0;
}