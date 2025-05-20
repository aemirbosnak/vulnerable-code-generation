//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15
#define SIZE (ROWS * COLS)

void multiplyMatrices(int **matrixA, int **matrixB, int **result, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);

int main() {
    int i, j, k, start, end;
    int **matrixA = (int **)calloc(ROWS, sizeof(int *));
    int **matrixB = (int **)calloc(ROWS, sizeof(int *));
    int **result = (int **)calloc(ROWS, sizeof(int *));

    for (i = 0; i < ROWS; i++) {
        matrixA[i] = (int *)calloc(COLS, sizeof(int));
        matrixB[i] = (int *)calloc(COLS, sizeof(int));
        result[i] = (int *)calloc(COLS, sizeof(int));
    }

    srand(time(NULL));

    // Fill matrices with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
        }
    }

    start = clock();

    // Multiply matrices
    multiplyMatrices(matrixA, matrixB, result, ROWS, COLS);

    end = clock();

    // Print results
    printf("Matrix A:\n");
    for (i = 0; i < ROWS; i++) {
        printMatrix(matrixA[i], COLS, 1);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < ROWS; i++) {
        printMatrix(matrixB[i], COLS, 1);
        printf("\n");
    }

    printf("\nResult:\n");
    for (i = 0; i < ROWS; i++) {
        printMatrix(result[i], COLS, 1);
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROWS; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(result[i]);
    }
    free(matrixA);
    free(matrixB);
    free(result);

    printf("\nTime taken to multiply matrices: %.10fs\n", (end - start) / CLOCKS_PER_SEC);

    return 0;
}

void multiplyMatrices(int **matrixA, int **matrixB, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}