//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

void displayMatrix(int matrix[][100], int rows, int columns) {
    printf("\nMatrix:\n");
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrixA[][100], int matrixB[][100], int rows, int columns) {
    int sumMatrix[rows][columns];
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    displayMatrix(sumMatrix, rows, columns);
}

void multiplyMatrix(int matrixA[][100], int matrixB[][100], int rowsA, int columnsA, int rowsB, int columnsB) {
    int productMatrix[rowsA][columnsB];
    if(columnsA != rowsB) {
        printf("\nError: Number of columns in matrix A should be equal to number of rows in matrix B.");
        return;
    }
    for(int i=0; i < rowsA; i++) {
        for(int j=0; j < columnsB; j++) {
            productMatrix[i][j] = 0;
            for(int k=0; k < columnsA; k++) {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    displayMatrix(productMatrix, rowsA, columnsB);
}

int main() {
    int matrixA[100][100], matrixB[100][100], rows, columns, rowsA, columnsA, rowsB, columnsB;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);
    printf("\nEnter elements of matrix A:\n");
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("\nMatrix A:");
    displayMatrix(matrixA, rows, columns);
    printf("\n");
    printf("Enter elements of matrix B:\n");
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    printf("\nMatrix B:");
    displayMatrix(matrixB, rows, columns);
    printf("\n");
    printf("Addition of Matrix A and Matrix B:\n");
    addMatrix(matrixA, matrixB, rows, columns);
    printf("\nEnter number of rows in Matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter number of columns in Matrix A: ");
    scanf("%d", &columnsA);
    printf("Enter elements of matrix A:\n");
    for(int i=0; i < rowsA; i++) {
        for(int j=0; j < columnsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    printf("\nMatrix A:");
    displayMatrix(matrixA, rowsA, columnsA);
    printf("\n");
    printf("Enter number of rows in Matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter number of columns in Matrix B: ");
    scanf("%d", &columnsB);
    printf("Enter elements of matrix B:\n");
    for(int i=0; i < rowsB; i++) {
        for(int j=0; j < columnsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    printf("\nMatrix B:");
    displayMatrix(matrixB, rowsB, columnsB);
    printf("\n");
    printf("Product of Matrix A and Matrix B:\n");
    multiplyMatrix(matrixA, matrixB, rowsA, columnsA, rowsB, columnsB);
    return 0;
}