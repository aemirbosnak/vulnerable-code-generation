//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {

    // The Basics: Allocating and Freeing Memory

    int *ptr = (int *)malloc(sizeof(int)); // Allocate 4 bytes for an integer
    *ptr = 42; // Store the value 42 in the allocated memory

    printf("The value we stored in memory is: %d\n", *ptr); // Print the value stored

    free(ptr); // Free the allocated memory when done

    // Dynamically Sized Arrays

    int num_elements;
    printf("How many elements do you want to store? ");
    scanf("%d", &num_elements);

    int *array = (int *)malloc(sizeof(int) * num_elements); // Allocate memory for the array

    // Fill the array with values
    for (int i = 0; i < num_elements; i++) {
        printf("Enter value %d: ", i);
        scanf("%d", &array[i]);
    }

    // Print the array elements
    printf("The array elements are: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }

    free(array); // Free the array memory

    // Advanced Memory Management: Pointers to Pointers

    int **ptr_to_ptr = (int **)malloc(sizeof(int *)); // Allocate memory for a pointer to a pointer
    *ptr_to_ptr = (int *)malloc(sizeof(int)); // Allocate memory for the inner pointer
    **ptr_to_ptr = 100; // Store the value 100 in the doubly pointed-to memory

    printf("The value stored in the doubly pointed-to memory is: %d\n", **ptr_to_ptr); // Print the value

    free(*ptr_to_ptr); // Free the inner pointer
    free(ptr_to_ptr); // Free the pointer to a pointer

    // Memory Leaks: What Not to Do!

    int *ptr_leak = (int *)malloc(sizeof(int)); // Allocate memory that is not freed
    *ptr_leak = 99; // Store a value in the leaked memory

    printf("This is a memory leak! The allocated memory will not be freed.\n");

    return 0;
}