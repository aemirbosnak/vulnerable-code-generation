//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define SIZE 100

// Generate a random array of numbers
int *generate_array(int size) {
    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Print the array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Search for a number in the array using linear search
int linear_search(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

// Search for a number in the array using binary search
int binary_search(int *array, int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Test the searching algorithms
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random array of numbers
    int *array = generate_array(SIZE);

    // Print the array
    printf("Array: ");
    print_array(array, SIZE);

    // Search for a number in the array using linear search
    int target = 50;
    int result = linear_search(array, SIZE, target);
    if (result == -1) {
        printf("Number not found using linear search.\n");
    } else {
        printf("Number found at index %d using linear search.\n", result);
    }

    // Search for the same number in the array using binary search
    result = binary_search(array, SIZE, target);
    if (result == -1) {
        printf("Number not found using binary search.\n");
    } else {
        printf("Number found at index %d using binary search.\n", result);
    }

    // Free the memory allocated for the array
    free(array);

    return 0;
}