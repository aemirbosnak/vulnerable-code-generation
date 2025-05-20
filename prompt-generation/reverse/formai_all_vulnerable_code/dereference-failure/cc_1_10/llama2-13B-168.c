//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3
#define MATRIX_NAME "my_matrix"

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(double) * rows * cols);
    return mat;
}

void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *mat1, matrix_t *mat2) {
    int i, j;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            mat1->data[i * mat1->cols + j] += mat2->data[i * mat2->cols + j];
        }
    }
}

void multiply_matrix(matrix_t *mat1, matrix_t *mat2) {
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            double sum = 0;
            for (k = 0; k < mat2->rows; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            mat1->data[i * mat1->cols + j] = sum;
        }
    }
}

int main() {
    matrix_t *mat1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    // Initialize matrix 1 with some values
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1->data[i * MATRIX_COLS + j] = (double)i * j;
        }
    }

    // Initialize matrix 2 with some values
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat2->data[i * MATRIX_COLS + j] = (double)(i * MATRIX_COLS + j);
        }
    }

    // Add matrices
    add_matrix(mat1, mat2);

    // Print result
    print_matrix(mat1);

    // Multiply matrices
    multiply_matrix(mat1, mat2);

    // Print result
    print_matrix(mat1);

    return 0;
}