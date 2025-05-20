//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Structure to hold the array of integers
typedef struct {
    int *array;
    int size;
} array_t;

// Function to sort the array using insertion sort
void sort_insertion(array_t *arr) {
    int i, j, min_idx, temp;

    // Loop through the array
    for (i = 1; i < arr->size; i++) {
        // Find the smallest unsorted element
        min_idx = i;
        for (j = i + 1; j < arr->size; j++) {
            if (arr->array[j] < arr->array[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the smallest unsorted element with the first element of the current index
        temp = arr->array[min_idx];
        arr->array[min_idx] = arr->array[i];
        arr->array[i] = temp;
    }
}

// Function to generate a random array of integers
void generate_random_array(array_t *arr) {
    int i, random_number;

    // Initialize the array with random numbers
    for (i = 0; i < ARRAY_SIZE; i++) {
        random_number = rand() % 100;
        arr->array[i] = random_number;
    }
}

// Function to print the sorted array
void print_sorted_array(array_t *arr) {
    int i;

    // Print the sorted array
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

int main() {
    array_t arr;

    // Initialize the array with random numbers
    generate_random_array(&arr);

    // Sort the array using insertion sort
    sort_insertion(&arr);

    // Print the sorted array
    print_sorted_array(&arr);

    return 0;
}