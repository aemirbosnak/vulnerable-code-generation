//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdlib.h>
#include <stdio.h>

// Declare a custom data structure
typedef struct {
    int *data;
    int size;
} CustomArray;

// Function to create a new CustomArray
CustomArray *create_array(int size) {
    CustomArray *array = (CustomArray *) malloc(sizeof(CustomArray));
    if (array == NULL) {
        printf("Error: Could not allocate memory for CustomArray.\n");
        exit(1);
    }
    array->data = (int *) malloc(sizeof(int) * size);
    if (array->data == NULL) {
        printf("Error: Could not allocate memory for CustomArray data.\n");
        exit(1);
    }
    array->size = size;
    return array;
}

// Function to free the memory allocated for a CustomArray
void free_array(CustomArray *array) {
    if (array == NULL) {
        printf("Warning: Trying to free a NULL CustomArray.\n");
        return;
    }
    if (array->data != NULL) {
        free(array->data);
    }
    free(array);
}

// Function to print the contents of a CustomArray
void print_array(CustomArray *array) {
    if (array == NULL) {
        printf("Warning: Trying to print a NULL CustomArray.\n");
        return;
    }
    printf("[");
    for (int i = 0; i < array->size; i++) {
        printf("%d, ", array->data[i]);
    }
    printf("]\n");
}

int main() {
    // Create a new CustomArray
    CustomArray *array = create_array(5);

    // Populate the array with data
    for (int i = 0; i < array->size; i++) {
        array->data[i] = i * 2;
    }

    // Print the contents of the array
    printf("Array contents: ");
    print_array(array);

    // Free the memory allocated for the array
    free_array(array);

    return 0;
}