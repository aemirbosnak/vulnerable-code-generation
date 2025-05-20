//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

void init_matrix(matrix_t *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)calloc(rows * cols, sizeof(int));
}

void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *result) {
    int i, j;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
        }
    }
}

void multiply_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *result) {
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
}

int main() {
    matrix_t mat1, mat2, result;

    // Initialize matrices
    init_matrix(&mat1, 5, 5);
    init_matrix(&mat2, 3, 4);
    init_matrix(&result, 5, 4);

    // Add matrices
    add_matrices(&mat1, &mat2, &result);

    // Multiply matrices
    multiply_matrices(&mat1, &mat2, &result);

    // Print result
    print_matrix(&result);

    return 0;
}