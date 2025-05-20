//FormAI DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Shape Shift function to change the memory allocation size
void shapeShift(int** pointer, int newSize) {
    int* newMemory = realloc(*pointer, newSize * sizeof(int));
    if (newMemory == NULL) {
        printf("Memory reallocation failed\n");
    } else {
        *pointer = newMemory;
    }
}

int main() {
    // Initial memory allocation of 5 integers
    int* pointer = malloc(5 * sizeof(int));
    if (pointer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Populate the memory allocation with some values
    for (int i = 0; i < 5; i++) {
        pointer[i] = i + 1;
    }

    // Print the values
    printf("Initial Values:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", pointer[i]);
    }
    printf("\n");

    // Shape shift the memory allocation to 10 integers
    shapeShift(&pointer, 10);

    // Populate the newly allocated memory with some values
    for (int i = 5; i < 10; i++) {
        pointer[i] = i + 1;
    }

    // Print the values
    printf("After Shapeshift 1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", pointer[i]);
    }
    printf("\n");

    // Shape shift the memory allocation to 3 integers
    shapeShift(&pointer, 3);

    // Print the values
    printf("After Shapeshift 2:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", pointer[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(pointer);
    pointer = NULL;

    return 0;
}