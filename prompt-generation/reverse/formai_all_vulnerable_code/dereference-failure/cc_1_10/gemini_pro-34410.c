//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

// Function to generate a random array of integers
int* generate_array(int size) {
    int* arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX;
    }
    return arr;
}

// Function to perform linear search on an array
int linear_search(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search on an array
int binary_search(int* arr, int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate a random array of integers
    int* arr = generate_array(MAX);

    // Define the target value to be searched
    int target = rand() % MAX;

    // Perform linear search on the array
    int linear_search_index = linear_search(arr, MAX, target);
    if (linear_search_index == -1) {
        printf("Target not found using linear search.\n");
    } else {
        printf("Target found at index %d using linear search.\n", linear_search_index);
    }

    // Perform binary search on the array
    int binary_search_index = binary_search(arr, MAX, target);
    if (binary_search_index == -1) {
        printf("Target not found using binary search.\n");
    } else {
        printf("Target found at index %d using binary search.\n", binary_search_index);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}