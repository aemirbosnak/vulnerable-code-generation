//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 15
#define MATRIX_SIZE (MATRIX_ROWS * MATRIX_COLS)

typedef struct {
    double *data;
    int rows;
    int cols;
} matrix_t;

void init_matrix(matrix_t *mat) {
    mat->data = (double *)calloc(MATRIX_SIZE, sizeof(double));
    mat->rows = MATRIX_ROWS;
    mat->cols = MATRIX_COLS;
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
            double sum = 0;
            for (k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
}

int main() {
    srand(time(NULL));

    matrix_t mat1, mat2, result;
    init_matrix(&mat1);
    init_matrix(&mat2);
    init_matrix(&result);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1.data[i * mat1.cols + j] = (double)rand() / RAND_MAX;
            mat2.data[i * mat2.cols + j] = (double)rand() / RAND_MAX;
        }
    }

    add_matrices(&mat1, &mat2, &result);
    print_matrix(&result);

    multiply_matrices(&mat1, &mat2, &result);
    print_matrix(&result);

    return 0;
}