//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Function to generate a random array
int *generate_random_array(int size) {
    int *array = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Function to print the array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to search for an element in the array using linear search
int linear_search(int *array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to search for an element in the array using binary search
int binary_search(int *array, int size, int element) {
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

// Function to test the searching algorithms
void test_searching_algorithms() {
    // Generate a random array
    int *array = generate_random_array(MAX_SIZE);

    // Print the array
    printf("Array: ");
    print_array(array, MAX_SIZE);

    // Search for an element in the array using linear search
    int element = 50;
    int index = linear_search(array, MAX_SIZE, element);
    if (index != -1) {
        printf("Element %d found at index %d using linear search\n", element, index);
    } else {
        printf("Element %d not found using linear search\n", element);
    }

    // Search for the same element in the array using binary search
    index = binary_search(array, MAX_SIZE, element);
    if (index != -1) {
        printf("Element %d found at index %d using binary search\n", element, index);
    } else {
        printf("Element %d not found using binary search\n", element);
    }

    // Free the memory allocated for the array
    free(array);
}

int main() {
    test_searching_algorithms();
    return 0;
}