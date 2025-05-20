//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// custom data type to store element and its index
typedef struct {
    int element;
    int index;
} elem_index;

// comparison function for qsort
int compare_elem_index(const void *a, const void *b) {
    return ((elem_index *)a)->element - ((elem_index *)b)->element;
}

// function to sort the array and return sorted indices
int *sort_and_get_indices(int *arr, int size) {
    // create an array of elem_index structs
    elem_index *arr_with_indices = malloc(size * sizeof(elem_index));
    for (int i = 0; i < size; i++) {
        arr_with_indices[i].element = arr[i];
        arr_with_indices[i].index = i;
    }
    // sort the array of elem_index structs
    qsort(arr_with_indices, size, sizeof(elem_index), compare_elem_index);

    // allocate memory for the sorted indices array
    int *sorted_indices = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sorted_indices[i] = arr_with_indices[i].index;
    }
    // free the allocated memory
    free(arr_with_indices);
    return sorted_indices;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 8, 3, 1, 9, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    int *sorted_indices = sort_and_get_indices(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[sorted_indices[i]]);
    }
    printf("\n");

    printf("Sorted indices: ");
    print_array(sorted_indices, size);

    free(sorted_indices);
    return 0;
}