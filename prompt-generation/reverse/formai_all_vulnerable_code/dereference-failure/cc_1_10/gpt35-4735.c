//FormAI DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function to print the matrix
void print_matrix(int **matrix, int rows, int cols)
{
    printf("Matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void add_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nAddition Result:\n");
    print_matrix(result, rows, cols);
}

// function to subtract two matrices
void subtract_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    printf("\nSubtraction Result:\n");
    print_matrix(result, rows, cols);
}

// function to multiply two matrices
void multiply_matrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int rows2, int cols2)
{
    if (cols1 != rows2) {
        printf("Matrix dimensions mismatch for multiplication\n");
        return;
    }

    int sum;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf("\nMultiplication Result:\n");
    print_matrix(result, rows1, cols2);
}

int main()
{
    int rows1 = 3;
    int cols1 = 2;
    int rows2 = 2;
    int cols2 = 3;

    // allocate memory for matrix1
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    // initialize matrix1
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;
    matrix1[2][0] = 5;
    matrix1[2][1] = 6;

    // allocate memory for matrix2
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // initialize matrix2
    matrix2[0][0] = 7;
    matrix2[0][1] = 8;
    matrix2[0][2] = 9;
    matrix2[1][0] = 10;
    matrix2[1][1] = 11;
    matrix2[1][2] = 12;

    // allocate memory for result matrix
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // print input matrices
    print_matrix(matrix1, rows1, cols1);
    printf("\n");
    print_matrix(matrix2, rows2, cols2);

    // add matrices
    add_matrices(matrix1, matrix2, result, rows1, cols2);

    // subtract matrices
    subtract_matrices(matrix1, matrix2, result, rows1, cols2);

    // multiply matrices
    multiply_matrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    // free memory
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