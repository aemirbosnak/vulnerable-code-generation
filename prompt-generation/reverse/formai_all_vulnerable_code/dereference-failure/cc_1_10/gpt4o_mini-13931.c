//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index of found element
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Return index of found element
        }
        if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if not found
}

// Function to generate a sorted array of unique integers
void generateSortedArray(int arr[], int size) {
    srand(time(NULL)); // Seed for random number generation
    arr[0] = rand() % 100; // Initialize the first element
    
    // Fill the array with unique sorted numbers
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + (rand() % 10 + 1); // Ensure uniqueness and sorting
    }
}

// Function to display an array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function for user interaction
int main() {
    int size, target, choice;

    printf("Welcome to the Searching Algorithm Program!\n");
    printf("Enter the number of elements to generate a sorted array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(sizeof(int) * size); // Allocate memory for the array
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    generateSortedArray(array, size);
    displayArray(array, size);

    printf("Options:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Choose a searching method (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the value to search for: ");
    scanf("%d", &target);

    int index = -1; // Variable to store the index of the found element

    switch (choice) {
        case 1:
            index = linearSearch(array, size, target);
            break;
        case 2:
            index = binarySearch(array, size, target);
            break;
        default:
            printf("Invalid choice!\n");
            free(array); // Free allocated memory
            return 1; // Exit if invalid choice
    }

    if (index != -1) {
        printf("Element %d found at index: %d\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    free(array); // Free allocated memory
    printf("Thank you for using the Searching Algorithm Program!\n");

    return 0;
}