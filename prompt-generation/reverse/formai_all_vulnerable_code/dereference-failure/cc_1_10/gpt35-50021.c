//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printMatrix(int **matrix, int rows, int cols);
int **addMatrices(int **matrix1, int **matrix2, int rows, int cols);
int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);

int main() 
{
    // input matrix1
    int rows1, cols1;
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    int **matrix1 = (int **) malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *) malloc(cols1 * sizeof(int));
    }

    printf("\nEnter matrix 1 values (row-wise):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // input matrix2
    int rows2, cols2;
    printf("\nEnter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    int **matrix2 = (int **) malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *) malloc(cols2 * sizeof(int));
    }

    printf("\nEnter matrix 2 values (row-wise):\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // print matrix1 and matrix2
    printf("\nMatrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    // add matrices
    if (rows1 == rows2 && cols1 == cols2) {
        printf("\nAdding matrices...\n");

        int **addedMatrix = addMatrices(matrix1, matrix2, rows1, cols1);

        printf("\nResultant matrix after addition:\n");
        printMatrix(addedMatrix, rows1, cols1);
    } else {
        printf("\nCannot add matrices of different shapes!\n");
    }

    // multiply matrices
    if (cols1 == rows2) {
        printf("\nMultiplying matrices...\n");

        int **multipliedMatrix = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);

        printf("\nResultant matrix after multiplication:\n");
        printMatrix(multipliedMatrix, rows1, cols2);
    } else {
        printf("\nCannot multiply matrices of incompatible shapes!\n");
    }

    // free memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **addMatrices(int **matrix1, int **matrix2, int rows, int cols)
{
    int **addedMatrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        addedMatrix[i] = (int *) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            addedMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return addedMatrix;
}

int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2)
{
    int **multipliedMatrix = (int **) malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        multipliedMatrix[i] = (int *) calloc(cols2, sizeof(int));
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                multipliedMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return multipliedMatrix;
}