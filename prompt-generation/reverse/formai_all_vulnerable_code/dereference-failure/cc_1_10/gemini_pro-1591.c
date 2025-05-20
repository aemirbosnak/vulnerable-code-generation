//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 10000

// Define the number of elements to search for
#define NUM_SEARCH 100

// Define the range of values for the elements in the array
#define MIN_VALUE 0
#define MAX_VALUE 1000

// Function to generate a random array of integers
int *generate_array(int size) {
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    return array;
}

// Function to search for an element in an array using linear search
int linear_search(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

// Function to search for an element in an array using binary search
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

// Function to test the performance of the linear search and binary search algorithms
void test_search_algorithms(int size, int num_search) {
    // Generate a random array of integers
    int *array = generate_array(size);

    // Create a list of random target values
    int *targets = malloc(num_search * sizeof(int));
    for (int i = 0; i < num_search; i++) {
        targets[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // Time the linear search algorithm
    clock_t start = clock();
    for (int i = 0; i < num_search; i++) {
        linear_search(array, size, targets[i]);
    }
    clock_t end = clock();
    double linear_search_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Time the binary search algorithm
    start = clock();
    for (int i = 0; i < num_search; i++) {
        binary_search(array, size, targets[i]);
    }
    end = clock();
    double binary_search_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Size: %d\n", size);
    printf("Number of searches: %d\n", num_search);
    printf("Linear search time: %f seconds\n", linear_search_time);
    printf("Binary search time: %f seconds\n", binary_search_time);
}

int main() {
    // Test the search algorithms for different array sizes and number of searches
    for (int size = 1000; size <= 10000; size += 1000) {
        for (int num_search = 100; num_search <= 1000; num_search += 100) {
            test_search_algorithms(size, num_search);
        }
    }
    return 0;
}