//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Fill with random values between 0 and 9
        }
    }
}

void addMatrices(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int aRows, int aCols, int bCols, int a[aRows][aCols], int b[aCols][bCols], int result[aRows][bCols]) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0; // Initialize result matrix element
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rowsA = 3, colsA = 3;
    int rowsB = 3, colsB = 3;

    int A[rowsA][colsA];
    int B[rowsB][colsB];
    int C[rowsA][colsB];
    int D[rowsA][colsA];
    int E[rowsA][colsA];

    // Seed for random number generation
    srand(42);

    // Fill and display matrices A and B
    fillMatrix(rowsA, colsA, A);
    fillMatrix(rowsB, colsB, B);
    printMatrix(rowsA, colsA, A);
    printMatrix(rowsB, colsB, B);

    // Add and display the sum of A and B
    addMatrices(rowsA, colsA, A, B, D);
    printf("Sum of A and B:\n");
    printMatrix(rowsA, colsA, D);

    // Subtract and display the difference of A and B
    subtractMatrices(rowsA, colsA, A, B, E);
    printf("Difference of A and B:\n");
    printMatrix(rowsA, colsA, E);

    // Multiply A with B
    multiplyMatrices(rowsA, colsA, colsB, A, B, C);
    printf("Product of A and B:\n");
    printMatrix(rowsA, colsB, C);

    return 0;
}