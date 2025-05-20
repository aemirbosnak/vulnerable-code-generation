//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random array of integers
int* generate_random_array(int size) {
    int* array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Function to print an array
void print_array(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}

// Function to search for an element in an array using sequential search
int sequential_search(int* array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to search for an element in an array using binary search
int binary_search(int* array, int size, int target) {
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

// Function to test the searching algorithms
void test_searching_algorithms() {
    int size = MAX_SIZE;
    int* array = generate_random_array(size);

    // Print the original array
    printf("Original array:\n");
    print_array(array, size);

    // Search for a target element using sequential search
    int target = 50;
    int index = sequential_search(array, size, target);

    if (index != -1) {
        printf("Target element found at index %d using sequential search.\n", index);
    } else {
        printf("Target element not found using sequential search.\n");
    }

    // Search for the same target element using binary search
    index = binary_search(array, size, target);

    if (index != -1) {
        printf("Target element found at index %d using binary search.\n", index);
    } else {
        printf("Target element not found using binary search.\n");
    }

    // Free the allocated memory
    free(array);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Test the searching algorithms
    test_searching_algorithms();

    return 0;
}