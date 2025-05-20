//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10
#define MAX_BITS 32

int main() {
    int num_bits, num_numbers, i, j, k;
    int *numbers;
    int **matrix;

    // Get the number of bits and numbers
    printf("Enter the number of bits: ");
    scanf("%d", &num_bits);
    printf("Enter the number of numbers: ");
    scanf("%d", &num_numbers);

    // Allocate memory for the numbers and matrix
    numbers = (int *)malloc(num_numbers * sizeof(int));
    matrix = (int **)malloc(num_numbers * sizeof(int *));
    for (i = 0; i < num_numbers; i++) {
        matrix[i] = (int *)malloc(num_bits * sizeof(int));
    }

    // Get the numbers from the user
    printf("Enter the numbers:\n");
    for (i = 0; i < num_numbers; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Perform bitwise operations on the numbers
    printf("\nBitwise operations:\n");
    for (i = 0; i < num_numbers; i++) {
        for (j = 0; j < num_bits; j++) {
            matrix[i][j] = numbers[i] & (1 << j);
        }
    }

    // Print the results
    printf("\nResults:\n");
    for (i = 0; i < num_numbers; i++) {
        for (j = 0; j < num_bits; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < num_numbers; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(numbers);

    return 0;
}