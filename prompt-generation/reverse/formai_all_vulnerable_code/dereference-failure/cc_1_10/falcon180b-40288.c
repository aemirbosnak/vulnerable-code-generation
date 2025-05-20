//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 1000000
#define NUM_COLS 1000000

int main() {
    int **matrix;
    int i, j;
    clock_t start, end;

    // Allocate memory for the matrix
    matrix = (int **) malloc(NUM_ROWS * sizeof(int *));
    for (i = 0; i < NUM_ROWS; i++) {
        matrix[i] = (int *) malloc(NUM_COLS * sizeof(int));
    }

    // Initialize the matrix with random numbers
    srand(time(NULL));
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Perform matrix multiplication
    start = clock();
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < NUM_COLS; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            matrix[i][j] = sum;
        }
    }
    end = clock();

    // Print the result
    printf("Matrix multiplication completed in %ld seconds.\n", end - start);

    // Free memory
    for (i = 0; i < NUM_ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}