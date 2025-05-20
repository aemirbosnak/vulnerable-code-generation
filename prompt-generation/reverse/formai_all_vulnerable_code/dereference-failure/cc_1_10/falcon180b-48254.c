//Falcon-180B DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2;
    int size1, size2;

    // Allocate memory dynamically for first array
    printf("Enter the size of first array: ");
    scanf("%d", &size1);
    ptr1 = (int*) malloc(size1 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Error: Memory not allocated\n");
        exit(0);
    }

    // Allocate memory dynamically for second array
    printf("Enter the size of second array: ");
    scanf("%d", &size2);
    ptr2 = (int*) malloc(size2 * sizeof(int));
    if (ptr2 == NULL) {
        printf("Error: Memory not allocated\n");
        exit(0);
    }

    // Fill the first array with values
    printf("Enter the values for first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &ptr1[i]);
    }

    // Fill the second array with values
    printf("Enter the values for second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &ptr2[i]);
    }

    // Display the contents of the first array
    printf("\nContents of first array:\n");
    for (int i = 0; i < size1; i++) {
        printf("%d ", ptr1[i]);
    }

    // Display the contents of the second array
    printf("\nContents of second array:\n");
    for (int i = 0; i < size2; i++) {
        printf("%d ", ptr2[i]);
    }

    // Free the memory allocated for first array
    free(ptr1);
    printf("\nMemory allocated for first array is freed\n");

    // Free the memory allocated for second array
    free(ptr2);
    printf("\nMemory allocated for second array is freed\n");

    return 0;
}