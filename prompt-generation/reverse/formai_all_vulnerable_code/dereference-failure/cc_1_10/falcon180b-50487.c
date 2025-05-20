//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0
#define PI 3.14159265358979323846

int main() {
    int i, j, n;
    int *arr;
    int sum = 0;
    int bitwise_sum = 0;

    // Allocate memory for array
    arr = (int *)malloc(MAX_SIZE * sizeof(int));

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Print original array
    printf("Original Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate sum using bitwise operators
    for (i = 0; i < MAX_SIZE; i++) {
        bitwise_sum += arr[i];
    }

    // Print result
    printf("Sum of Array using Bitwise Operators: %d\n", bitwise_sum);

    // Calculate sum using loop
    for (i = 0; i < MAX_SIZE; i++) {
        sum += arr[i];
    }

    // Print result
    printf("Sum of Array using Loop: %d\n", sum);

    // Free memory
    free(arr);

    return 0;
}