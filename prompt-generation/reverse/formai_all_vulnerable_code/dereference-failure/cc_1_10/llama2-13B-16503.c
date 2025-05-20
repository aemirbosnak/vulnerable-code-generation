//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    matrix_t *result = new_matrix(rows1 + rows2, cols1 + cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }

    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scalar) {
    int rows = mat->rows;
    int cols = mat->cols;
    matrix_t *result = new_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->matrix[i][j] = scalar * mat->matrix[i][j];
        }
    }

    return result;
}

int main() {
    srand(time(NULL));

    // Create a 3x3 matrix
    matrix_t *mat = new_matrix(3, 3);

    // Initialize the matrix with some random values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat->matrix[i][j] = rand() % 10;
        }
    }

    // Print the matrix
    print_matrix(mat);

    // Add two matrices
    matrix_t *mat2 = new_matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat2->matrix[i][j] = rand() % 10;
        }
    }
    matrix_t *result = add_matrices(mat, mat2);
    print_matrix(result);

    // Scale a matrix by a scalar
    matrix_t *scaled_mat = scale_matrix(mat, 2);
    print_matrix(scaled_mat);

    return 0;
}