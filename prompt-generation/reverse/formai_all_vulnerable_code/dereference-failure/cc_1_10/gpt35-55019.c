//FormAI DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to display the matrix
void displayMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Matrices cannot be multiplied\n");
        return;
    }
    int **resultingMatrix = (int **)malloc(rows1 * sizeof(int *));
    for(int i = 0; i < rows1; i++) {
        resultingMatrix[i] = (int *)malloc(cols2 * sizeof(int));
        for(int j = 0; j < cols2; j++) {
            resultingMatrix[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                resultingMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    displayMatrix(resultingMatrix, rows1, cols2);
}

int main() {
    int rows1, cols1;
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d%d", &rows1, &cols1);

    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for(int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        printf("Enter the elements for row %d: ", i + 1);
        for(int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    int rows2, cols2;
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d%d", &rows2, &cols2);

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for(int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        printf("Enter the elements for row %d: ", i + 1);
        for(int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\n");

    // Perform matrix multiplication
    multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);

    // Free memory
    for(int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    for(int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}