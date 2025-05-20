//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
//This is a Matrix Operations Example program in C Turing style
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int rows, int columns) {
    //Prints the matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int **matrix1, int **matrix2, int **result, int rows1, int columns1, int rows2, int columns2) {
    //Multiplies two matrices and stores the result in 'result'
    if (columns1 != rows2) {
        printf("Error: Matrices cannot be multiplied.");
        return;
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, columns1, rows2, columns2;

    printf("Enter the number of rows for Matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for Matrix 1: ");
    scanf("%d", &columns1);

    printf("Enter the number of rows for Matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for Matrix 2: ");
    scanf("%d", &columns2);

    //Dynamically allocate memory for matrices
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(columns1 * sizeof(int));
    }

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(columns2 * sizeof(int));
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(columns2 * sizeof(int));
    }

    //Initialize matrices with user input
    printf("\nEnter the elements for Matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\n");
    printMatrix(matrix1, rows1, columns1);

    printf("\nEnter the elements for Matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\n");
    printMatrix(matrix2, rows2, columns2);

    //Multiply matrices and print result
    printf("\n");
    multiplyMatrix(matrix1, matrix2, result, rows1, columns1, rows2, columns2);
    printMatrix(result, rows1, columns2);

    //Free dynamically allocated memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}