//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x;
    int *y;

    // Allocate memory for x
    x = (int*)malloc(sizeof(int));

    // Check if x allocation was successful
    if (x == NULL) {
        printf("Error: memory allocation for x failed.");
        return 1;
    }

    // Assign a value to x
    *x = 10;

    // Print the value of x
    printf("The value of x: %d\n", *x);

    // Allocate memory for y
    y = (int*)calloc(5, sizeof(int));

    // Check if y allocation was successful
    if (y == NULL) {
        printf("Error: memory allocation for y failed.");
        return 1;
    }

    // Assign values to y
    for (int i=0; i<5; i++) {
        y[i] = i;
    }

    // Print the values of y
    printf("The values of y: ");
    for (int i=0; i<5; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    // Reallocate memory for y
    y = (int*)realloc(y, sizeof(int)*10);

    // Check if y reallocation was successful
    if (y == NULL) {
        printf("Error: memory allocation for y failed.");
        return 1;
    }

    // Assign values to new elements of y
    for (int i=5; i<10; i++) {
        y[i] = i;
    }

    // Print the new values of y
    printf("The new values of y: ");
    for (int i=0; i<10; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    // Free memory allocated for x and y
    free(x);
    free(y);

    return 0;
}