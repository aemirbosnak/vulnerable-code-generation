//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);
}

void initMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100;
}

int multiplyMatrix(int **a, int **b, int **c, int aRows, int aCols, int bRows, int bCols) {
    if (aCols != bRows) {
        return -1;
    }

    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            c[i][j] = 0;

            for (int k = 0; k < aCols; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return 0;
}

int main() {
    // Generate random matrices
    srand(time(NULL));

    int aRows = 1000;
    int aCols = 1000;
    int bRows = 1000;
    int bCols = 1000;
    int **a = createMatrix(aRows, aCols);
    int **b = createMatrix(bRows, bCols);
    int **c = createMatrix(aRows, bCols);

    initMatrix(a, aRows, aCols);
    initMatrix(b, bRows, bCols);

    // Time the matrix multiplication
    clock_t start = clock();
    multiplyMatrix(a, b, c, aRows, aCols, bRows, bCols);
    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to multiply matrices: %f seconds\n", timeTaken);

    freeMatrix(a, aRows);
    freeMatrix(b, bRows);
    freeMatrix(c, aRows);

    return 0;
}