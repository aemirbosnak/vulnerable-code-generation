//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a dynamic array
typedef struct {
    int capacity;
    int size;
    int *elements;
} dynamic_array;

// Function to allocate memory for a dynamic array
dynamic_array *da_alloc(int capacity) {
    dynamic_array *da = malloc(sizeof(dynamic_array));
    da->capacity = capacity;
    da->size = 0;
    da->elements = malloc(capacity * sizeof(int));
    return da;
}

// Function to free memory for a dynamic array
void da_free(dynamic_array *da) {
    free(da->elements);
    free(da);
}

// Function to insert an element into a dynamic array
int da_insert(dynamic_array *da, int element) {
    if (da->size == da->capacity) {
        // Increase capacity by 50%
        da->capacity *= 2;
        da->elements = realloc(da->elements, da->capacity * sizeof(int));
    }
    da->elements[da->size] = element;
    da->size++;
    return da->size - 1;
}

// Function to access an element from a dynamic array
int da_access(dynamic_array *da, int index) {
    return da->elements[index];
}

// Function to delete an element from a dynamic array
void da_delete(dynamic_array *da, int index) {
    if (index < da->size) {
        // Shift elements to fill the gap
        for (int i = index; i < da->size - 1; i++) {
            da->elements[i] = da->elements[i + 1];
        }
        da->size--;
    }
}

int main() {
    dynamic_array *da = da_alloc(10);

    // Insert elements into the dynamic array
    da_insert(da, 1);
    da_insert(da, 2);
    da_insert(da, 3);
    da_insert(da, 4);
    da_insert(da, 5);

    // Access and delete elements from the dynamic array
    printf("Elements in the dynamic array: ");
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da_access(da, i));
    }
    printf("\n");

    da_delete(da, 2);

    // Print the updated dynamic array
    printf("Elements in the dynamic array after deletion: ");
    for (int i = 0; i < da->size; i++) {
        printf("%d ", da_access(da, i));
    }
    printf("\n");

    da_free(da);

    return 0;
}