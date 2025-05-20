//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(sizeof(int) * cols);
    }
    return mat;
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][0] + mat2->data[0][j];
        }
    }
    return result;
}

matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols * mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            for (int k = 0; k < mat1->cols; k++) {
                result->data[i][j * mat1->cols + k] =
                    mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result1 = add_matrices(mat1, mat2);
    matrix_t *result2 = multiply_matrices(mat1, mat2);
    print_matrix(result1);
    print_matrix(result2);
    return 0;
}