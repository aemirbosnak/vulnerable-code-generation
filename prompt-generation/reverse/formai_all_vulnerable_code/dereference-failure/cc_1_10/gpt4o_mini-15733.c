//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array of random integers
void generateRandomArray(int* array, int size, int max_value) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % max_value; // Random integers in range [0, max_value)
    }
}

// Function to perform linear search
int linearSearch(int* array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i; // Return the index of the found item
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform binary search (requires the array to be sorted)
int binarySearch(int* array, int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2; // Prevent overflow

        if (array[middle] == target) {
            return middle; // Return the index of the found item
        }
        if (array[middle] < target) {
            left = middle + 1; // Move to the right half
        } else {
            right = middle - 1; // Move to the left half
        }
    }
    return -1; // Return -1 if not found
}

// Function to sort an array using bubble sort
void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to display array contents
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int size = 20;
    int max_value = 100;
    int target;
    int* array = (int*)malloc(size * sizeof(int)); // Allocate memory for array

    // Generate random array
    generateRandomArray(array, size, max_value);
    printf("Generated Random Array: ");
    printArray(array, size);

    // Perform a linear search
    printf("Enter a number to search through Linear Search: ");
    scanf("%d", &target);
    
    int index = linearSearch(array, size, target);
    if (index != -1) {
        printf("Linear Search: Element %d found at index %d.\n", target, index);
    } else {
        printf("Linear Search: Element %d not found in the array.\n", target);
    }

    // Sort the array using bubble sort
    bubbleSort(array, size);
    printf("Sorted Array: ");
    printArray(array, size);

    // Perform a binary search
    printf("Enter a number to search through Binary Search: ");
    scanf("%d", &target);
    
    index = binarySearch(array, size, target);
    if (index != -1) {
        printf("Binary Search: Element %d found at index %d.\n", target, index);
    } else {
        printf("Binary Search: Element %d not found in the sorted array.\n", target);
    }

    free(array); // Free allocated memory
    return 0;
}