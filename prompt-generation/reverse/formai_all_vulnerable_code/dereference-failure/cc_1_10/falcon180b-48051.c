//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main() {
    int i, j, k;
    int *arr;
    int *arr2;
    int *arr3;
    int sum;

    // Allocate memory for arrays
    arr = (int *) malloc(SIZE * sizeof(int));
    arr2 = (int *) malloc(SIZE * sizeof(int));
    arr3 = (int *) malloc(SIZE * sizeof(int));

    // Initialize arrays with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
        arr2[i] = rand() % 10;
    }

    // Perform bitwise AND operation on two arrays and store result in third array
    for (i = 0; i < SIZE; i++) {
        arr3[i] = arr[i] & arr2[i];
    }

    // Print original arrays and bitwise AND result
    printf("Original arrays:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Bitwise AND result:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Free memory allocated for arrays
    free(arr);
    free(arr2);
    free(arr3);

    return 0;
}