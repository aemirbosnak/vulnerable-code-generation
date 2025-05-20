//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void allocateMatrix(int ***matrix, int rows, int cols) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }
}

void freeMatrix(int **matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int **a, int **b, int **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int **a, int **b, int **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int **a, int **b, int **result, int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int **matrix, int **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB, choice;
    int **matrixA, **matrixB, **result;

    printf("Matrix Operations Program\n");
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    allocateMatrix(&matrixA, rowsA, colsA);
    inputMatrix(matrixA, rowsA, colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    allocateMatrix(&matrixB, rowsB, colsB);
    inputMatrix(matrixB, rowsB, colsB);

    printf("Select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose Matrix A\n5. Transpose Matrix B\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rowsA != rowsB || colsA != colsB) {
                printf("Addition not possible. Matrices must be of same dimensions.\n");
                break;
            }
            allocateMatrix(&result, rowsA, colsA);
            addMatrices(matrixA, matrixB, result, rowsA, colsA);
            printMatrix(result, rowsA, colsA);
            freeMatrix(result, rowsA);
            break;

        case 2:
            if (rowsA != rowsB || colsA != colsB) {
                printf("Subtraction not possible. Matrices must be of same dimensions.\n");
                break;
            }
            allocateMatrix(&result, rowsA, colsA);
            subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
            printMatrix(result, rowsA, colsA);
            freeMatrix(result, rowsA);
            break;

        case 3:
            if (colsA != rowsB) {
                printf("Multiplication not possible. Columns of A must equal rows of B.\n");
                break;
            }
            allocateMatrix(&result, rowsA, colsB);
            multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
            printMatrix(result, rowsA, colsB);
            freeMatrix(result, rowsA);
            break;

        case 4:
            allocateMatrix(&result, colsA, rowsA);
            transposeMatrix(matrixA, result, rowsA, colsA);
            printMatrix(result, colsA, rowsA);
            freeMatrix(result, colsA);
            break;

        case 5:
            allocateMatrix(&result, colsB, rowsB);
            transposeMatrix(matrixB, result, rowsB, colsB);
            printMatrix(result, colsB, rowsB);
            freeMatrix(result, colsB);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    return 0;
}