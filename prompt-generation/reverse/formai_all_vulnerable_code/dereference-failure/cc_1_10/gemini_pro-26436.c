//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random array of integers.
int* generate_array(int size) {
    int* array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Search for a target value in an array using linear search.
int linear_search(int* array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

// Search for a target value in an array using binary search.
int binary_search(int* array, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Print the array.
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Set the random seed.
    srand(time(NULL));

    // Generate an array of 10 random integers.
    int* array = generate_array(10);

    // Print the array.
    printf("Array: ");
    print_array(array, 10);

    // Search for the value 50 using linear search.
    int index = linear_search(array, 10, 50);
    if (index == -1) {
        printf("Value not found using linear search.\n");
    } else {
        printf("Value found at index %d using linear search.\n", index);
    }

    // Search for the value 50 using binary search.
    index = binary_search(array, 10, 50);
    if (index == -1) {
        printf("Value not found using binary search.\n");
    } else {
        printf("Value found at index %d using binary search.\n", index);
    }

    // Free the array.
    free(array);

    return 0;
}