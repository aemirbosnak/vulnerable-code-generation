//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct {
    int *arr;
    int size;
} ArrayWrapper;

// Function to initialize the array
ArrayWrapper initialize_array(int size) {
    ArrayWrapper arrayWrapper;
    arrayWrapper.size = size;
    arrayWrapper.arr = (int *)malloc(size * sizeof(int));
    
    // Populate the array with random integers for demonstration
    for (int i = 0; i < size; i++) {
        arrayWrapper.arr[i] = rand() % 200;  // Random integers between 0 and 199
    }
    
    return arrayWrapper;
}

// Function to print the array
void print_array(ArrayWrapper arrayWrapper) {
    printf("Array contents:\n");
    for (int i = 0; i < arrayWrapper.size; i++) {
        printf("%d ", arrayWrapper.arr[i]);
    }
    printf("\n");
}

// Function to sort the array (using Bubble Sort for simplicity)
void bubble_sort(ArrayWrapper arrayWrapper) {
    int n = arrayWrapper.size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrayWrapper.arr[j] > arrayWrapper.arr[j + 1]) {
                // Swap
                int temp = arrayWrapper.arr[j];
                arrayWrapper.arr[j] = arrayWrapper.arr[j + 1];
                arrayWrapper.arr[j + 1] = temp;
            }
        }
    }
}

// Binary search function
int binary_search(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Target found
        }
        
        if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    
    return -1;  // Target not found
}

// Function to clean up the allocated array
void free_array(ArrayWrapper arrayWrapper) {
    free(arrayWrapper.arr);
}

int main() {
    int n;
    printf("Enter the number of elements for the array (up to %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_ELEMENTS) {
        fprintf(stderr, "Invalid number of elements! Must be between 1 and %d.\n", MAX_ELEMENTS);
        return EXIT_FAILURE;
    }

    ArrayWrapper arrayWrapper = initialize_array(n);
    print_array(arrayWrapper);

    // Sort the array before performing binary search
    bubble_sort(arrayWrapper);
    printf("Sorted ");
    print_array(arrayWrapper);

    // Input the target we are searching for
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int result = binary_search(arrayWrapper.arr, arrayWrapper.size, target);
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    free_array(arrayWrapper);
    return EXIT_SUCCESS;
}