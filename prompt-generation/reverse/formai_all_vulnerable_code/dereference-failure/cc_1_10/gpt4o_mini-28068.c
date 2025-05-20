//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100
#define MAX_RANGE 1000

typedef struct {
    int *array;
    int size;
} DynamicArray;

// Function Prototypes
DynamicArray* create_dynamic_array(int size);
void populate_array(DynamicArray *d_array);
void print_array(DynamicArray *d_array);
int linear_search(DynamicArray *d_array, int target);
int binary_search(DynamicArray *d_array, int target);
void sort_array(DynamicArray *d_array);
void free_dynamic_array(DynamicArray *d_array);

int main() {
    srand(time(NULL)); // Seed for randomness
    int size = rand() % MAX_ELEMENTS + 1; // Random size between 1 and MAX_ELEMENTS
    DynamicArray *dynamic_array = create_dynamic_array(size);
    
    printf("Populating and displaying the array...\n");
    populate_array(dynamic_array);
    print_array(dynamic_array);
    
    int target;
    printf("Enter a number between 0 and %d to search: ", MAX_RANGE);
    scanf("%d", &target);

    // Searching in the unsorted array using linear search
    int linear_index = linear_search(dynamic_array, target);
    if (linear_index != -1) {
        printf("Linear Search: Found %d at index %d\n", target, linear_index);
    } else {
        printf("Linear Search: %d not found in the array.\n", target);
    }

    // Sorting array to perform binary search
    sort_array(dynamic_array);
    printf("Array sorted for binary search:\n");
    print_array(dynamic_array);

    int binary_index = binary_search(dynamic_array, target);
    if (binary_index != -1) {
        printf("Binary Search: Found %d at index %d\n", target, binary_index);
    } else {
        printf("Binary Search: %d not found in the array.\n", target);
    }

    free_dynamic_array(dynamic_array);
    return 0;
}

DynamicArray* create_dynamic_array(int size) {
    DynamicArray *d_array = (DynamicArray *)malloc(sizeof(DynamicArray));
    d_array->array = (int *)malloc(size * sizeof(int));
    d_array->size = size;
    return d_array;
}

void populate_array(DynamicArray *d_array) {
    for (int i = 0; i < d_array->size; i++) {
        d_array->array[i] = rand() % MAX_RANGE;
    }
}

void print_array(DynamicArray *d_array) {
    for (int i = 0; i < d_array->size; i++) {
        printf("%d ", d_array->array[i]);
    }
    printf("\n");
}

int linear_search(DynamicArray *d_array, int target) {
    for (int i = 0; i < d_array->size; i++) {
        if (d_array->array[i] == target) {
            return i;
        }
    }
    return -1; // Not found
}

void sort_array(DynamicArray *d_array) {
    for (int i = 0; i < d_array->size - 1; i++) {
        for (int j = 0; j < d_array->size - i - 1; j++) {
            if (d_array->array[j] > d_array->array[j + 1]) {
                int temp = d_array->array[j];
                d_array->array[j] = d_array->array[j + 1];
                d_array->array[j + 1] = temp;
            }
        }
    }
}

int binary_search(DynamicArray *d_array, int target) {
    int left = 0, right = d_array->size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (d_array->array[mid] == target) {
            return mid;
        } else if (d_array->array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

void free_dynamic_array(DynamicArray *d_array) {
    free(d_array->array);
    free(d_array);
}