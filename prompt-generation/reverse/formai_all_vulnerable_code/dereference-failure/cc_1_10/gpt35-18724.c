//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// function to print matrix
void printMatrix(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add matrices
int ** addMatrix(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = (int **) malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        result[i] = (int *) malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// function to multiply matrices
int ** multiplyMatrix(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = (int **) malloc(rows1 * sizeof(int *));
    for(int i = 0; i < rows1; i++) {
        result[i] = (int *) malloc(cols2 * sizeof(int));
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    // take input from user for matrix 1
    int rows1, cols1;
    printf("Enter rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    int **matrix1 = (int **) malloc(rows1 * sizeof(int *));
    for(int i = 0; i < rows1; i++) {
        matrix1[i] = (int *) malloc(cols1 * sizeof(int));
    }

    printf("\nEnter matrix 1 elements:\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // take input from user for matrix 2
    int rows2, cols2;
    printf("\nEnter rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    int **matrix2 = (int **) malloc(rows2 * sizeof(int *));
    for(int i = 0; i < rows2; i++) {
        matrix2[i] = (int *) malloc(cols2 * sizeof(int));
    }

    printf("\nEnter matrix 2 elements:\n");
    for(int i = 0; i < rows2; i++) {
        for(int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    // add matrices
    if(rows1 == rows2 && cols1 == cols2) {
        int **sum = addMatrix(matrix1, matrix2, rows1, cols1);
        printf("\nSum of the matrices:\n");
        printMatrix(sum, rows1, cols1);
    } else {
        printf("\nMatrices cannot be added.\n");
    }

    // multiply matrices
    if(cols1 == rows2) {
        int **product = multiplyMatrix(matrix1, matrix2, rows1, cols1, cols2);
        printf("\nProduct of the matrices:\n");
        printMatrix(product, rows1, cols2);
    } else {
        printf("\nMatrices cannot be multiplied.\n");
    }

    return 0;
}