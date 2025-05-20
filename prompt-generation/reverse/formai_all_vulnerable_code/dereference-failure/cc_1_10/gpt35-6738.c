//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000

// Function to generate a random array
void generateRandomArray(int *arr) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the array
void printArray(int *arr) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort
void bubbleSort(int *arr) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    // Seed for the random number generator
    srand(time(NULL));

    // Allocate memory for the array
    int *arr = (int*) malloc(N * sizeof(int));

    // Generate a random array
    generateRandomArray(arr);

    // Print the unsorted array
    printf("Unsorted array: ");
    printArray(arr);

    // Start the timer
    clock_t start = clock();

    // Sort the array
    bubbleSort(arr);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken for sorting
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr);

    // Print the time taken for sorting
    printf("Time taken: %lf seconds\n", timeTaken);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}