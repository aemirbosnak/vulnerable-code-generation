//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10000
#define COLS 10000

int main() {
    int **matrix;
    int i, j;
    clock_t start, end;

    // Allocate memory for the matrix
    matrix = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the matrix with random numbers
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Measure the time it takes to sum all elements in the matrix
    start = clock();
    int sum = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    end = clock();

    // Print the sum and the time it took to compute it
    printf("\nSum: %d\n", sum);
    printf("Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free the memory allocated for the matrix
    for (i = 0; i < ROWS; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}