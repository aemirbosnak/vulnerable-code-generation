//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define SORT_ASCENDING  1
#define SORT_DESCENDING 2
#define SORT_NO_SORT    0

typedef struct {
    int *arr;
    int size;
    int sort_order;
} int_array_t;

int_array_t *create_int_array(int *arr, int size, int sort_order) {
    int_array_t *ia = malloc(sizeof(int_array_t));
    ia->arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        ia->arr[i] = arr[i];
    }
    ia->size = size;
    ia->sort_order = sort_order;
    return ia;
}

void free_int_array(int_array_t *ia) {
    free(ia->arr);
    free(ia);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int_array_t *ia) {
    for (int i = 0; i < ia->size - 1; i++) {
        for (int j = 0; j < ia->size - i - 1; j++) {
            if ((ia->sort_order == SORT_ASCENDING && ia->arr[j] > ia->arr[j + 1]) ||
                (ia->sort_order == SORT_DESCENDING && ia->arr[j] < ia->arr[j + 1])) {
                swap(&ia->arr[j], &ia->arr[j + 1]);
            }
        }
    }
}

void print_int_array(int_array_t *ia) {
    printf("[");
    for (int i = 0; i < ia->size; i++) {
        printf("%d", ia->arr[i]);
        if (i < ia->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Create an array of integers
    int arr[] = {5, 3, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create an int_array_t struct to hold the array and its properties
    int_array_t *ia = create_int_array(arr, size, SORT_ASCENDING);

    // Sort the array in ascending order
    bubble_sort(ia);

    // Print the sorted array
    printf("Sorted array (ascending): ");
    print_int_array(ia);

    // Change the sort order to descending
    ia->sort_order = SORT_DESCENDING;

    // Sort the array in descending order
    bubble_sort(ia);

    // Print the sorted array
    printf("Sorted array (descending): ");
    print_int_array(ia);

    // Free the memory allocated for the int_array_t struct
    free_int_array(ia);

    return 0;
}