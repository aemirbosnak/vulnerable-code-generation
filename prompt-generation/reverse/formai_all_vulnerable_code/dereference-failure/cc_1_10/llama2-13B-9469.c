//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Structure to store matrix information
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)calloc(rows * cols, sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
        }
    }
    return result;
}

// Function to subtract one matrix from another
matrix_t *subtract_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] - mat2->data[i * mat2->cols + j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scalar) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = scalar * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

// Function to transpose a matrix
matrix_t *transpose_matrix(matrix_t *mat) {
    matrix_t *result = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->cols; i++) {
        for (int j = 0; j < mat->rows; j++) {
            result->data[i * result->rows + j] = mat->data[j * mat->cols + i];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(3, 4);
    matrix_t *mat2 = create_matrix(4, 3);
    matrix_t *result;

    // Initialize matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat1->data[i * 4 + j] = i * j;
        }
    }

    // Add matrices
    result = add_matrices(mat1, mat2);
    print_matrix(result);

    // Subtract matrices
    result = subtract_matrices(mat1, mat2);
    print_matrix(result);

    // Scale matrix
    result = scale_matrix(mat1, 2);
    print_matrix(result);

    // Transpose matrix
    result = transpose_matrix(mat1);
    print_matrix(result);

    return 0;
}