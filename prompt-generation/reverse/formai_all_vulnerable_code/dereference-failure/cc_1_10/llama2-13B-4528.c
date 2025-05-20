//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int add_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    int **result = (int **) malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *) malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
int *multiply_matrix_by_scalar(int **matrix, int rows, int cols, int scalar) {
    int *result = (int *) malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    int rows1 = 3, cols1 = 4, rows2 = 2, cols2 = 3;
    int **matrix1 = (int **) malloc(rows1 * sizeof(int *));
    int **matrix2 = (int **) malloc(rows2 * sizeof(int *));
    int **result = (int **) malloc(rows1 * sizeof(int *));

    // Initialize matrix1
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *) malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = i * j;
        }
    }

    // Initialize matrix2
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *) malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = i * j + 1;
        }
    }

    // Add matrix1 and matrix2
    int *result_add = add_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    print_matrix(result_add, rows1, cols2);

    // Multiply matrix1 by 2
    int *result_multiply = multiply_matrix_by_scalar(matrix1, rows1, cols1, 2);
    print_matrix(result_multiply, rows1, cols1);

    free(matrix1);
    free(matrix2);
    free(result_add);
    free(result_multiply);

    return 0;
}