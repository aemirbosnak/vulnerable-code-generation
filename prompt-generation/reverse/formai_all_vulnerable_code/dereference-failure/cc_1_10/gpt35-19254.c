//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h> 

int **createMatrix(int rows, int cols) {
    int **matrix = malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **addMatrix(int **matrixA, int **matrixB, int rows, int cols) {
    int **result = malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int **subtractMatrix(int **matrixA, int **matrixB, int rows, int cols) {
    int **result = malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

int **multiplyMatrix(int **matrixA, int **matrixB, int rowsA, int colsA, int colsB) {
    int **result = malloc(rowsA * sizeof(int *));
    for(int i = 0; i < rowsA; i++) {
        result[i] = malloc(colsB * sizeof(int));
        for(int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for(int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    int **matrixA = createMatrix(rowsA, colsA);
    printf("Enter the elements of matrix A:\n");
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("\nEnter rows and columns of matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    int **matrixB = createMatrix(rowsB, colsB);
    printf("Enter the elements of matrix B:\n");
    for(int i = 0; i < rowsB; i++) {
        for(int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    if(colsA != rowsB) {
        printf("Matrices cannot be multiplied!\n");
    } else {
        printf("\nMatrix A:\n");
        printMatrix(matrixA, rowsA, colsA);
        printf("\nMatrix B:\n");
        printMatrix(matrixB, rowsB, colsB);
        int **sum = addMatrix(matrixA, matrixB, rowsA, colsA);
        printf("\nMatrix sum:\n");
        printMatrix(sum, rowsA, colsA);
        int **difference = subtractMatrix(matrixA, matrixB, rowsA, colsA);
        printf("\nMatrix difference:\n");
        printMatrix(difference, rowsA, colsA);
        int **product = multiplyMatrix(matrixA, matrixB, rowsA, colsA, colsB);
        printf("\nMatrix product:\n");
        printMatrix(product, rowsA, colsB);
    }
    return 0;
}