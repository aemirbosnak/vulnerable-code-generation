//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10000
#define COLS 10000

int main() {
    int i, j;
    int **matrix = (int **)malloc(ROWS * sizeof(int *)); // Allocate memory for the matrix
    clock_t start, end;

    for (i = 0; i < ROWS; i++) {
        matrix[i] = (int *)malloc(COLS * sizeof(int)); // Allocate memory for each row in the matrix
    }

    srand(time(NULL)); // Seed the random number generator

    // Fill the matrix with random integers between 0 and 99
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    start = clock(); // Start the timer

    // Find the maximum value in the matrix
    int max = matrix[0][0];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    end = clock(); // Stop the timer

    printf("The maximum value in the matrix is %d\n", max);
    printf("Time taken to find the maximum value: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free the memory allocated for the matrix
    for (i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}