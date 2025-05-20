//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int main() {
    int *arr, i, sum_sq;
    int *sum_sq_arr;

    // Allocate memory for the first array
    arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the first array
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }

    // Allocate memory for the second array
    sum_sq_arr = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (sum_sq_arr == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        return 1;
    }

    // Calculate and store the sum of squares in the second array
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum_sq = arr[i] * arr[i];
        sum_sq_arr[i] = sum_sq;
    }

    // Free the memory allocated for the first array
    free(arr);

    // Print the first array
    printf("First array elements:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the second array
    printf("Sum of squares array elements:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", sum_sq_arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the second array
    free(sum_sq_arr);

    return 0;
}