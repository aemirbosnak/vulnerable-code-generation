//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int rows, int columns, int matrix[rows][columns]) {
    printf("Matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int rowsA, int columnsA, int matrixA[rowsA][columnsA], 
                    int rowsB, int columnsB, int matrixB[rowsB][columnsB], 
                    int resultMatrix[rowsA][columnsB]) {
    for(int i=0; i<rowsA; i++) {
        for(int j=0; j<columnsB; j++) {
            resultMatrix[i][j] = 0;
            for(int k=0; k<columnsA; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int rowsA = 3, columnsA = 2;
    int rowsB = 2, columnsB = 4;
    
    int matrixA[rowsA][columnsA];
    int matrixB[rowsB][columnsB];
    int resultMatrix[rowsA][columnsB];
    
    // Initialize matrixA with random values between 1 and 10
    for(int i=0; i<rowsA; i++) {
        for(int j=0; j<columnsA; j++) {
            matrixA[i][j] = rand() % 10 + 1;
        }
    }
    
    // Initialize matrixB with random values between 1 and 10
    for(int i=0; i<rowsB; i++) {
        for(int j=0; j<columnsB; j++) {
            matrixB[i][j] = rand() % 10 + 1;
        }
    }
    
    printf("Matrix A has %d row(s) and %d column(s):\n", rowsA, columnsA);
    printMatrix(rowsA, columnsA, matrixA);
    
    printf("Matrix B has %d row(s) and %d column(s):\n", rowsB, columnsB);
    printMatrix(rowsB, columnsB, matrixB);
    
    multiplyMatrix(rowsA, columnsA, matrixA, rowsB, columnsB, matrixB, resultMatrix);
    
    printf("Result of multiplying Matrix A by Matrix B:\n");
    printMatrix(rowsA, columnsB, resultMatrix);
    
    return 0;
}