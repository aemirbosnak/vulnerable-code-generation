//FormAI DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int *ptr1, *ptr2, *ptr3, *ptr4;

    // Allocating a block of 20 integers of size 4 bytes each
    ptr1 = (int*)malloc(20 * sizeof(int));

    // Checking if the memory was allocated successfully
    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Filling the allocated memory with integers
    for (int i = 0; i < 20; i++) {
        ptr1[i] = i * 2;
    }

    // Printing the allocated memory
    for (int i = 0; i < 20; i++) {
        printf("%d ", ptr1[i]);
    }

    printf("\n");

    // Reallocating the memory block to store 15 integers
    ptr2 = (int*)realloc(ptr1, 15 * sizeof(int));

    // Checking if the memory was reallocated successfully
    if (ptr2 == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }

    // Printing the reallocated memory
    for (int i = 0; i < 15; i++) {
        printf("%d ", ptr2[i]);
    }

    printf("\n");

    // Freeing the second half of the memory block
    ptr3 = &ptr2[SIZE];
    free(ptr3);

    // Printing the memory after freeing
    for (int i = 0; i < 15; i++) {
        printf("%d ", ptr2[i]);
    }

    printf("\n");

    // Allocating a block of 5 integers of size 4 bytes each
    ptr4 = (int*)calloc(5, sizeof(int));

    // Checking if the memory was allocated successfully
    if (ptr4 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Printing the allocated memory
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr4[i]);
    }

    printf("\n");

    // Freeing the allocated memory
    free(ptr2);
    free(ptr4);

    return 0;
}