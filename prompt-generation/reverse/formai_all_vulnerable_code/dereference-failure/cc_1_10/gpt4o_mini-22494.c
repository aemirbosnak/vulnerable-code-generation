//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** addMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

int** multiplyMatrices(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    int** result = createMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rowsA = 2, colsA = 3;
    int rowsB = 2, colsB = 3;
    int rowsC = 3, colsC = 2;
    
    int** matrixA = createMatrix(rowsA, colsA);
    int** matrixB = createMatrix(rowsB, colsB);
    
    // Initialize matrixA
    int count = 1;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            matrixA[i][j] = count++;
        }
    }
    
    // Initialize matrixB
    count = 1;
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            matrixB[i][j] = count++;
        }
    }

    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, colsA);
    
    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, colsB);
    
    // Test Matrix Addition
    printf("Matrix A + Matrix B (Only same sized matrices):\n");
    int** addResult = addMatrices(matrixA, matrixB, rowsA, colsA);
    printMatrix(addResult, rowsA, colsA);
    freeMatrix(addResult, rowsA);

    // Test Matrix Subtraction
    printf("Matrix B - Matrix A:\n");
    int** subResult = subtractMatrices(matrixB, matrixA, rowsB, colsB);
    printMatrix(subResult, rowsB, colsB);
    freeMatrix(subResult, rowsB);

    // Initialize another matrix for multiplication
    int** matrixC = createMatrix(rowsC, colsC);
    count = 1;
    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            matrixC[i][j] = count++;
        }
    }
    
    printf("Matrix C:\n");
    printMatrix(matrixC, rowsC, colsC);

    // Test Matrix Multiplication
    printf("Matrix A * Matrix C:\n");
    int** mulResult = multiplyMatrices(matrixA, matrixC, rowsA, colsA, colsC);
    printMatrix(mulResult, rowsA, colsC);
    freeMatrix(mulResult, rowsA);
    
    // Cleanup
    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    freeMatrix(matrixC, rowsC);
    
    return 0;
}