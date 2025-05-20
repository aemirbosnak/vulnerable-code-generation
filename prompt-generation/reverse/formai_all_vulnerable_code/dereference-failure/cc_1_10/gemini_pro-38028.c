//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define N 10

// Define a custom data structure
typedef struct {
    int *data;
    int size;
} array_t;

// Allocate memory for an array
array_t *array_new(int size) {
    array_t *array = malloc(sizeof(array_t));
    if (array == NULL) {
        return NULL;
    }

    array->data = malloc(size * sizeof(int));
    if (array->data == NULL) {
        free(array);
        return NULL;
    }

    array->size = size;
    return array;
}

// Free the memory allocated for an array
void array_free(array_t *array) {
    free(array->data);
    free(array);
}

// Print the contents of an array
void array_print(array_t *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// Fill an array with random numbers
void array_fill_random(array_t *array) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = rand() % 100;
    }
}

// Main function
int main() {
    // Allocate memory for an array
    array_t *array = array_new(N);

    // Fill the array with random numbers
    array_fill_random(array);

    // Print the contents of the array
    array_print(array);

    // Free the memory allocated for the array
    array_free(array);

    return 0;
}