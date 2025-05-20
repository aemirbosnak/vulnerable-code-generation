//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);

int main() {
    srand(time(0)); // Seed random number generator

    // Mind-bending maze of sizes
    int mazeSizes[] = {10, 50, 100, 500};
    int numberOfMazes = sizeof(mazeSizes) / sizeof(mazeSizes[0]);
    
    for (int i = 0; i < numberOfMazes; i++) {
        int size = mazeSizes[i];
        int *array = (int *)malloc(size * sizeof(int));

        // Generate random numbers
        generateRandomArray(array, size);
        printf("Generated Array of Size %d:\n", size);
        printArray(array, size);

        // Linear Search
        int target = array[rand() % size];
        printf("Linear Search for: %d\n", target);
        int linearResult = linearSearch(array, size, target);
        if (linearResult != -1) {
            printf("Found at index (Linear): %d\n\n", linearResult);
        } else {
            printf("Not Found (Linear)\n\n");
        }

        // Sort Array for Binary Search
        sortArray(array, size);
        printf("Sorted Array of Size %d:\n", size);
        printArray(array, size);

        // Binary Search
        printf("Binary Search for: %d\n", target);
        int binaryResult = binarySearch(array, size, target);
        if (binaryResult != -1) {
            printf("Found at index (Binary): %d\n\n", binaryResult);
        } else {
            printf("Not Found (Binary)\n\n");
        }

        free(array); // Free allocated memory
    }

    return 0;
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generate random numbers from 0 to 999
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Found
        }
    }
    return -1; // Not Found
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Found
        }
        if (arr[mid] < target) {
            low = mid + 1; // Move higher
        } else {
            high = mid - 1; // Move lower
        }
    }
    return -1; // Not Found
}