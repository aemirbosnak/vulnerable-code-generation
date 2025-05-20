//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int numRows, int numCols) {
    printf("\nMATRIX:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Let's do some matrix operations!\n");

    int numRows1 = 2;
    int numCols1 = 2;

    int **matrix1 = (int**)malloc(numRows1 * sizeof(int*));
    for (int i = 0; i < numRows1; i++) {
        matrix1[i] = (int*)malloc(numCols1 * sizeof(int));
        for (int j = 0; j < numCols1; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }

    int numRows2 = 2;
    int numCols2 = 2;

    int **matrix2 = (int**)malloc(numRows2 * sizeof(int*));
    for (int i = 0; i < numRows2; i++) {
        matrix2[i] = (int*)malloc(numCols2 * sizeof(int));
        for (int j = 0; j < numCols2; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    printMatrix(matrix1, numRows1, numCols1);
    printMatrix(matrix2, numRows2, numCols2);

    int numRowsResult = numRows1;
    int numColsResult = numCols2;

    int **resultMatrix = (int**)malloc(numRowsResult * sizeof(int*));
    for (int i = 0; i < numRowsResult; i++) {
        resultMatrix[i] = (int*)malloc(numColsResult * sizeof(int));
        for (int j = 0; j < numColsResult; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < numCols1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printMatrix(resultMatrix, numRowsResult, numColsResult);

    printf("Matrix operations complete!\n");

    return 0;
}