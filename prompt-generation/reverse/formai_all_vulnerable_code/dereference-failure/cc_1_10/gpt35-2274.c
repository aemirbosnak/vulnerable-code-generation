//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int n, i;

    // get input for size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // allocate memory dynamically
    ptr = (int*) malloc(n * sizeof(int));

    // check if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // get input for array elements
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // display array elements
    printf("Array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // reallocate memory for array
    n += 5;
    ptr = (int*) realloc(ptr, n * sizeof(int));

    // check if reallocation was successful
    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // set new array elements to 0
    for (i = n-5; i < n; i++) {
        ptr[i] = 0;
    }

    // display new array elements
    printf("New array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // free allocated memory
    free(ptr);

    return 0;
}