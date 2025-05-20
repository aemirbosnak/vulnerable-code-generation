//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3;

    // Allocate 10 integers using malloc()
    ptr1 = (int*) malloc(10 * sizeof(int));

    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Store values in the allocated memory
    for (int i = 0; i < 10; i++) {
        *(ptr1 + i) = i * 2;
    }

    // Allocate 5 integers using calloc()
    ptr2 = (int*) calloc(5, sizeof(int));

    if (ptr2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Store values in the allocated memory
    for (int i = 0; i < 5; i++) {
        *(ptr2 + i) = i * 5;
    }

    // Allocate memory for 3 more integers using realloc()
    ptr3 = (int*) realloc(ptr1, 13 * sizeof(int));

    if (ptr3 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Store values in the reallocated memory
    for (int i = 10; i < 13; i++) {
        *(ptr3 + i) = i * 3;
    }

    // Print values from ptr1
    printf("Values in ptr1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr1 + i));
    }

    // Print values from ptr2
    printf("\nValues in ptr2:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr2 + i));
    }

    // Print values from ptr3
    printf("\nValues in ptr3:\n");
    for (int i = 0; i < 13; i++) {
        printf("%d ", *(ptr3 + i));
    }

    // Free memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}