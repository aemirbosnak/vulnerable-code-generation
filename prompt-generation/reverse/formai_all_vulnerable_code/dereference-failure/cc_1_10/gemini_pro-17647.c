//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

int **matrix_allocate(int rows, int cols);
void matrix_free(int **matrix, int rows);
void matrix_print(int **matrix, int rows, int cols);
void matrix_transpose(int **matrix, int rows, int cols);
int **matrix_multiply(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2);

int main() {
    // Define the dimensions of the matrices
    int rows1 = 3;
    int cols1 = 2;
    int rows2 = 2;
    int cols2 = 3;

    // Allocate memory for the matrices
    int **matrix1 = matrix_allocate(rows1, cols1);
    int **matrix2 = matrix_allocate(rows2, cols2);

    // Initialize the matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = i + j;
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = i - j;
        }
    }

    // Print the original matrices
    printf("Matrix 1:\n");
    matrix_print(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    matrix_print(matrix2, rows2, cols2);

    // Transpose matrix 1
    matrix_transpose(matrix1, rows1, cols1);

    // Multiply the matrices
    int **matrix3 = matrix_multiply(matrix1, rows1, cols1, matrix2, rows2, cols2);

    // Print the resulting matrix
    printf("Matrix 3 (Result of Matrix 1 x Matrix 2):\n");
    matrix_print(matrix3, rows1, cols2);

    // Free the memory allocated for the matrices
    matrix_free(matrix1, rows1);
    matrix_free(matrix2, rows2);
    matrix_free(matrix3, rows1);

    return 0;
}

int **matrix_allocate(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void matrix_free(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void matrix_print(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_transpose(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int **matrix_multiply(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Matrix dimensions are incompatible for multiplication.\n");
        return NULL;
    }

    int **matrix3 = matrix_allocate(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return matrix3;
}