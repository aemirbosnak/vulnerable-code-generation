//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void fillArray(int *array, int size);
void displayArray(int *array, int size);
int* resizeArray(int *array, int newSize);
void freeMemory(int *array);

int main() {
    int size = 5;
    int *myArray = malloc(size * sizeof(int));

    // Check if memory allocation succeeded
    if (myArray == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Fill the array with values
    fillArray(myArray, size);
    printf("Initial array:\n");
    displayArray(myArray, size);

    // Resize the array
    size = 10; // New size
    myArray = resizeArray(myArray, size);

    // Fill the new elements
    fillArray(myArray + 5, 5); // Filling only the new spots
    printf("\nArray after resizing:\n");
    displayArray(myArray, size);

    // Resize again
    size = 3; // Shrinking
    myArray = resizeArray(myArray, size);
    printf("\nArray after shrinking:\n");
    displayArray(myArray, size);

    // Free the allocated memory
    freeMemory(myArray);

    return 0;
}

// Function to fill the array with incremental values
void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i + 1; // Fill with values 1, 2, 3, ...
    }
}

// Function to display the array elements
void displayArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to resize the array
int* resizeArray(int *array, int newSize) {
    int *newArray = realloc(array, newSize * sizeof(int));
    if (newArray == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        freeMemory(array);
        exit(1);
    }
    return newArray;
}

// Function to free allocated memory
void freeMemory(int *array) {
    free(array);
    printf("Memory freed successfully!\n");
}