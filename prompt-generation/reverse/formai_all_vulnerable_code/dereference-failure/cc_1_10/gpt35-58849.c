//FormAI DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printMatrix(int**, int, int);
int** createMatrix(int, int);
void freeMatrix(int**, int);
int** addMatrix(int**, int**, int, int);
int** multMatrix(int**, int**, int, int, int);

int main() {
    int rows = 3;
    int cols = 3;

    int** matrix1 = createMatrix(rows, cols);
    int** matrix2 = createMatrix(rows, cols);

    // populate matrices with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = rand()%10;
            matrix2[i][j] = rand()%10;
        }
    }

    // print matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows, cols);

    printf("Matrix 2:\n");
    printMatrix(matrix2, rows, cols);

    // add matrices
    int** sumMatrix = addMatrix(matrix1, matrix2, rows, cols);
    printf("Sum of matrices:\n");
    printMatrix(sumMatrix, rows, cols);

    // multiply matrices
    int rows2 = 4; // second matrix number of rows
    int** matrix3 = createMatrix(cols, rows2); // create second matrix
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows2; j++) {
            matrix3[i][j] = rand()%10; // populate second matrix
        }
    }

    int** multMatrixResult = multMatrix(matrix1, matrix3, rows, cols, rows2);
    printf("Multiplication of matrices:\n");
    printMatrix(multMatrixResult, rows, rows2);

    // free memory
    freeMatrix(matrix1, rows);
    freeMatrix(matrix2, rows);
    freeMatrix(sumMatrix, rows);
    freeMatrix(matrix3, cols);
    freeMatrix(multMatrixResult, rows);

    return 0;
}

// print matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// create matrix
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// free matrix memory
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// add two matrices
int** addMatrix(int** matrix1, int** matrix2, int rows, int cols) {
    int** sumMatrix = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sumMatrix;
}

// multiply two matrices
int** multMatrix(int** matrix1, int** matrix2, int rows1, int cols1, int rows2) {
    int** multMatrixResult = createMatrix(rows1, rows2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < rows2; j++) {
            multMatrixResult[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                multMatrixResult[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return multMatrixResult;
}