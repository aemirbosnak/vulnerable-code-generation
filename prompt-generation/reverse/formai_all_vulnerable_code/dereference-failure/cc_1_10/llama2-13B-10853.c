//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 5
#define COL_SIZE 7

// Structure to store a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
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
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[j][i];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scale) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = scale * mat->matrix[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(ROW_SIZE, COL_SIZE);
    matrix_t *mat2 = create_matrix(ROW_SIZE, COL_SIZE);
    matrix_t *result;

    // Initialize the matrices
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            mat1->matrix[i][j] = i * j;
            mat2->matrix[i][j] = i + j;
        }
    }

    // Add the matrices
    result = add_matrices(mat1, mat2);

    // Print the result
    print_matrix(result);

    // Scale the result by 2
    result = scale_matrix(result, 2);

    // Print the scaled result
    print_matrix(result);

    return 0;
}