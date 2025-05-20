//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int **matrix, int row, int col) {
    printf("Matrix:\n");
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition(int **matrixA, int **matrixB, int **result, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void matrixSubtraction(int **matrixA, int **matrixB, int **result, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void matrixMultiplication(int **matrixA, int **matrixB, int **result, int rowA, int colA, int colB) {
    for (int i=0; i<rowA; i++) {
        for (int j=0; j<colB; j++) {
            result[i][j] = 0;
            for (int k=0; k<colA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void matrixTranspose(int **matrix, int row, int col, int **result) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowA, colA, rowB, colB;
    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &rowA, &colA);

    int **matrixA = (int **)malloc(rowA * sizeof(int *));
    for (int i=0; i<rowA; i++) {
        matrixA[i] = (int *)malloc(colA * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (int i=0; i<rowA; i++) {
        for (int j=0; j<colA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &rowB, &colB);

    int **matrixB = (int **)malloc(rowB * sizeof(int *));
    for (int i=0; i<rowB; i++) {
        matrixB[i] = (int *)malloc(colB * sizeof(int));
    }

    printf("Enter elements of second matrix:\n");
    for (int i=0; i<rowB; i++) {
        for (int j=0; j<colB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    int **result = (int **)malloc(rowA * sizeof(int *));
    for (int i=0; i<rowA; i++) {
        result[i] = (int *)malloc(colB * sizeof(int));
    }

    if (colA != rowB) {
        printf("Matrix multiplication not possible.\n");
    } else {
        matrixMultiplication(matrixA, matrixB, result, rowA, colA, colB);
        displayMatrix(result, rowA, colB);
    }

    int **additionResult = (int **)malloc(rowA * sizeof(int *));
    for (int i=0; i<rowA; i++) {
        additionResult[i] = (int *)malloc(colA * sizeof(int));
    }

    matrixAddition(matrixA, matrixB, additionResult, rowA, colA);
    displayMatrix(additionResult, rowA, colA);

    int **subtractionResult = (int **)malloc(rowA * sizeof(int *));
    for (int i=0; i<rowA; i++) {
        subtractionResult[i] = (int *)malloc(colA * sizeof(int));
    }

    matrixSubtraction(matrixA, matrixB, subtractionResult, rowA, colA);
    displayMatrix(subtractionResult, rowA, colA);

    int **transposeResult = (int **)malloc(colA * sizeof(int *));
    for (int i=0; i<colA; i++) {
        transposeResult[i] = (int *)malloc(rowA * sizeof(int));
    }

    matrixTranspose(matrixA, rowA, colA, transposeResult);
    displayMatrix(transposeResult, colA, rowA);

    for (int i=0; i<rowA; i++) {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i=0; i<rowB; i++) {
        free(matrixB[i]);
    }
    free(matrixB);

    for (int i=0; i<rowA; i++) {
        free(result[i]);
    }
    free(result);

    for (int i=0; i<rowA; i++) {
        free(additionResult[i]);
    }
    free(additionResult);

    for (int i=0; i<rowA; i++) {
        free(subtractionResult[i]);
    }
    free(subtractionResult);

    for (int i=0; i<colA; i++) {
        free(transposeResult[i]);
    }
    free(transposeResult);

    return 0;
}