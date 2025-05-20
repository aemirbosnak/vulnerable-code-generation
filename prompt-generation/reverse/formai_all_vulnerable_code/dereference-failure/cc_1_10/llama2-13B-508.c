//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int) * rows * cols);
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    int i, j;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scale) {
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = scale * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(5, 7);
    matrix_t *mat2 = new_matrix(3, 5);
    matrix_t *result;

    // Initialize the matrices
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            mat1->data[i * 7 + j] = i * j;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            mat2->data[i * 5 + j] = i * j;
        }
    }

    // Add the matrices
    result = add_matrices(mat1, mat2);

    // Print the result
    print_matrix(result);

    // Scale the result by 2
    result = scale_matrix(result, 2);

    // Print the result again
    print_matrix(result);

    return 0;
}