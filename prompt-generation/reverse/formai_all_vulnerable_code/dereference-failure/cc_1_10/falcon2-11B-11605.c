//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr = NULL; // Declare a pointer to an integer array
    int size = 10; // Define the size of the array
    
    // Allocate memory for the array using malloc
    arr = (int*)malloc(size * sizeof(int));
    
    // Check if the memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }
    
    // Initialize the array elements with some values
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    
    // Print the array elements
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the allocated memory using free
    free(arr);
    
    // Reallocate memory for the array using realloc
    arr = (int*)realloc(arr, size * sizeof(int));
    
    // Check if the memory reallocation was successful
    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1; // Return an error code
    }
    
    // Print the array elements after reallocation
    printf("Reallocated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the allocated memory again using free
    free(arr);
    
    return 0;
}