//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to generate a random array of integers
int* generate_random_array(int size) {
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Function to print an array
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to search for an element in an array using linear search
int linear_search(int* array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to search for an element in an array using binary search
int binary_search(int* array, int size, int element) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (array[mid] == element) {
            return mid;
        } else if (array[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Function to test the linear and binary search algorithms
void test_search_algorithms() {
    // Generate a random array of integers
    int* array = generate_random_array(MAX_SIZE);

    // Print the original array
    printf("Original array: ");
    print_array(array, MAX_SIZE);

    // Search for an element in the array using linear search
    int element = 50;
    int linear_search_result = linear_search(array, MAX_SIZE, element);
    if (linear_search_result == -1) {
        printf("Element %d not found using linear search\n", element);
    } else {
        printf("Element %d found at index %d using linear search\n", element, linear_search_result);
    }

    // Search for the same element in the array using binary search
    int binary_search_result = binary_search(array, MAX_SIZE, element);
    if (binary_search_result == -1) {
        printf("Element %d not found using binary search\n", element);
    } else {
        printf("Element %d found at index %d using binary search\n", element, binary_search_result);
    }
}

int main() {
    // Test the linear and binary search algorithms
    test_search_algorithms();

    return 0;
}