//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(sizeof(int) * rows * cols);
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
    int i, j, k;
    matrix_t *result = init_matrix(mat1->rows, mat2->cols);
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++) {
                result->data[i * result->cols + j] += mat1->data[i * mat1->cols + k] + mat2->data[k * mat2->cols + j];
            }
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scale) {
    int i, j;
    matrix_t *result = init_matrix(mat->rows, mat->cols);
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = mat->data[i * mat->cols + j] * scale;
        }
    }
    return result;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    matrix_t *mat1 = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = init_matrix(MATRIX_ROWS, MATRIX_COLS);

    // Initialize matrix elements with random values
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1->data[i * MATRIX_COLS + j] = rand() % 10;
            mat2->data[i * MATRIX_COLS + j] = rand() % 10;
        }
    }

    // Add matrices
    matrix_t *result = add_matrices(mat1, mat2);

    // Print result
    print_matrix(result);

    // Scale matrix by 2
    matrix_t *scaled_mat = scale_matrix(result, 2);

    // Print scaled matrix
    print_matrix(scaled_mat);

    return 0;
}