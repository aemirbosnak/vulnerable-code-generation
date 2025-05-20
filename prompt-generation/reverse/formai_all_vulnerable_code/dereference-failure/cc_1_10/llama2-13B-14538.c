//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
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

void free_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

void add_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *res) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i][j] + mat2->data[j][i];
            res->data[i][j] = sum % 10;
        }
    }
}

int main() {
    matrix_t *mat1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *res = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1->data[i][j] = i * j % 10;
            mat2->data[i][j] = i * j % 10;
        }
    }

    add_matrices(mat1, mat2, res);

    print_matrix(res);

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(res);

    return 0;
}