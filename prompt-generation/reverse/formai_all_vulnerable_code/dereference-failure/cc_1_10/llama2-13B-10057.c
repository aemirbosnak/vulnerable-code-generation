//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Function to free memory allocated by new_matrix
void free_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

// Function to print a matrix
void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    int rows1 = matrix1->rows;
    int cols1 = matrix1->cols;
    int rows2 = matrix2->rows;
    int cols2 = matrix2->cols;
    matrix_t *result = new_matrix(rows1 + rows2, cols1 + cols2);
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            result->matrix[i][j] = matrix2->matrix[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *matrix, int scalar) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->matrix[i][j] *= scalar;
        }
    }
    return matrix;
}

int main() {
    matrix_t *matrix1 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *matrix2 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = add_matrices(matrix1, matrix2);
    print_matrix(result);
    matrix_t *scaled_result = scale_matrix(result, 2);
    print_matrix(scaled_result);
    free_matrix(result);
    free_matrix(scaled_result);
    return 0;
}