//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_MAX_ROWS 10
#define MATRIX_MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double *) malloc(sizeof(double) * rows * cols);
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

void free_matrix(matrix_t *mat) {
    free(mat->data);
    free(mat);
}

matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++) {
                result->data[i * result->cols + j] += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
        }
    }
    return result;
}

matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols * mat1->cols);
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++) {
                result->data[i * result->cols + j * mat1->cols + k] =
                    mat1->data[i * mat1->cols + k] * mat2->data[j * mat2->cols + k];
            }
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(5, 3);
    matrix_t *mat2 = create_matrix(3, 4);
    matrix_t *result1 = add_matrices(mat1, mat2);
    matrix_t *result2 = multiply_matrices(mat1, mat2);
    print_matrix(result1);
    print_matrix(result2);
    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(result1);
    free_matrix(result2);
    return 0;
}