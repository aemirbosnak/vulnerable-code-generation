//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Self-sorting function using introspective sorting algorithm
void introsort(int *array, size_t length) {
    // Base case: array with 0 or 1 elements is already sorted
    if (length <= 1) {
        return;
    }

    // Choose a pivot element
    int pivot = array[length / 2];

    // Partition the array into three parts: less than, equal to, and greater than the pivot
    int *less = malloc(length * sizeof(int));
    int *equal = malloc(length * sizeof(int));
    int *greater = malloc(length * sizeof(int));
    size_t less_count = 0;
    size_t equal_count = 0;
    size_t greater_count = 0;
    for (size_t i = 0; i < length; i++) {
        if (array[i] < pivot) {
            less[less_count++] = array[i];
        } else if (array[i] == pivot) {
            equal[equal_count++] = array[i];
        } else {
            greater[greater_count++] = array[i];
        }
    }

    // Recursively sort the less and greater partitions
    introsort(less, less_count);
    introsort(greater, greater_count);

    // Merge the sorted partitions back into the original array
    size_t i = 0;
    for (size_t j = 0; j < less_count; j++) {
        array[i++] = less[j];
    }
    for (size_t j = 0; j < equal_count; j++) {
        array[i++] = equal[j];
    }
    for (size_t j = 0; j < greater_count; j++) {
        array[i++] = greater[j];
    }

    // Free the temporary arrays
    free(less);
    free(equal);
    free(greater);
}

int main() {
    // Initialize an array of unsorted integers
    int array[] = {5, 3, 1, 2, 4};
    size_t length = sizeof(array) / sizeof(array[0]);

    // Sort the array using introspective sort
    introsort(array, length);

    // Print the sorted array
    printf("Sorted array: ");
    for (size_t i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}