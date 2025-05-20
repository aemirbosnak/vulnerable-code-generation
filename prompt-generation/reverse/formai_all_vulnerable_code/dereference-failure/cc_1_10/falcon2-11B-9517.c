//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare and define a 2D array of integers
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // Print the array elements
    printf("Before Dynamic Memory Allocation:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Dynamically allocate memory for the 2D array
    int *ptr = (int *)malloc(3 * 4 * sizeof(int));

    // Copy the values from the original array to the dynamically allocated array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            ptr[i * 4 + j] = arr[i][j];
        }
    }

    // Print the dynamically allocated array
    printf("After Dynamic Memory Allocation:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", ptr[i * 4 + j]);
        }
        printf("\n");
    }

    // Deallocate the dynamically allocated memory
    free(ptr);

    // Print the original array
    printf("After Deallocation:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}