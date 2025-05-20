//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int colsB, int matrixA[rowsA][colsA], int matrixB[colsA][colsB], int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Shape-Shifting Matrix Operations\n");
    printf("---------------------------------\n");
    
    // Matrix A Input
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    clearInputBuffer();

    int matrixA[rowsA][colsA];
    printf("Input Matrix A (%d x %d):\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Matrix B Input
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    clearInputBuffer();

    int matrixB[rowsB][colsB];
    printf("Input Matrix B (%d x %d):\n", rowsB, colsB);
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Result matrices
    int additionResult[rowsA][colsA];
    int subtractionResult[rowsA][colsA];
    
    // Checking for Addition and Subtraction
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(rowsA, colsA, matrixA, matrixB, additionResult);
        subtractMatrices(rowsA, colsA, matrixA, matrixB, subtractionResult);
        
        printf("Matrix A + Matrix B:\n");
        displayMatrix(rowsA, colsA, additionResult);

        printf("Matrix A - Matrix B:\n");
        displayMatrix(rowsA, colsA, subtractionResult);
    } else {
        printf("Addition and Subtraction is not possible due to dimension mismatch.\n");
    }

    // Checking for Multiplication
    if (colsA == rowsB) {
        int multiplicationResult[rowsA][colsB];
        multiplyMatrices(rowsA, colsA, colsB, matrixA, matrixB, multiplicationResult);
        
        printf("Matrix A * Matrix B:\n");
        displayMatrix(rowsA, colsB, multiplicationResult);
    } else {
        printf("Multiplication is not possible due to dimension mismatch.\n");
    }

    return 0;
}