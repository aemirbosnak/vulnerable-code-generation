//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
void benchmarkBubbleSort(int arr[], int n);

// A simple structure to hold benchmark results
typedef struct {
    double timeTaken;
    int arraySize;
} BenchmarkResult;

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Array sizes to benchmark
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    BenchmarkResult results[numSizes];

    // Loop through each size and benchmark the bubble sort
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *array = (int *)malloc(n * sizeof(int));

        // Generate random numbers and fill the array
        for (int j = 0; j < n; j++) {
            array[j] = rand() % 10000; // Limit random numbers to 0-9999
        }

        // Benchmark the bubble sort
        benchmarkBubbleSort(array, n);

        // Store results
        results[i].arraySize = n;
        results[i].timeTaken = (double)clock() / CLOCKS_PER_SEC; // Get time taken

        // Cleanup
        free(array);
    }

    // Display results
    printf("Bubble Sort Benchmark Results:\n");
    printf("Array Size\tTime Taken (seconds)\n");
    for (int i = 0; i < numSizes; i++) {
        printf("%d\t\t%.6f\n", results[i].arraySize, results[i].timeTaken);
    }

    return 0;
}

// Implementation of Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to benchmark the Bubble Sort
void benchmarkBubbleSort(int arr[], int n) {
    clock_t start, end;
    start = clock(); // Start time

    // Sort the array
    bubbleSort(arr, n);

    end = clock(); // End time
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC; // Calculate time taken

    // Display the time taken for sorting
    printf("Sorted an array of size %d in %.6f seconds.\n", n, timeSpent);
}