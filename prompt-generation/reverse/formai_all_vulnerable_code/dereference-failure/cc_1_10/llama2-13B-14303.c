//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)calloc(cols, sizeof(int));
    }
    return mat;
}

// Function to free a matrix
void free_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Invalid matrix sizes!\n");
        return NULL;
    }
    matrix_t *result = new_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scale) {
    if (scale <= 0) {
        printf("Invalid scale value!\n");
        return NULL;
    }
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = scale * mat->data[i][j];
        }
    }
    return result;
}

int main() {
    // Create a matrix
    matrix_t *mat = new_matrix(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat->data[i][j] = i * j;
        }
    }

    // Add two matrices
    matrix_t *mat2 = new_matrix(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat2->data[i][j] = i * j + 1;
        }
    }
    matrix_t *result = add_matrices(mat, mat2);
    if (result == NULL) {
        printf("Matrix addition failed!\n");
        return 1;
    }
    print_matrix(result);

    // Scale a matrix by a scalar
    matrix_t *scaled_mat = scale_matrix(mat, 2);
    if (scaled_mat == NULL) {
        printf("Matrix scaling failed!\n");
        return 1;
    }
    print_matrix(scaled_mat);

    // Free matrices
    free_matrix(mat);
    free_matrix(mat2);
    free_matrix(scaled_mat);
    return 0;
}