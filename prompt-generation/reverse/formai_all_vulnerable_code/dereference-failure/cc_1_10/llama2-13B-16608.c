//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **mat;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->mat[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *mat1, matrix_t *mat2) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            mat1->mat[i][j] += mat2->mat[i][j];
        }
    }
}

matrix_t *multiply_matrix(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->mat[i][k] * mat2->mat[k][j];
            }
            result->mat[i][j] = sum;
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(5, 3);
    matrix_t *mat2 = create_matrix(3, 4);
    matrix_t *result = multiply_matrix(mat1, mat2);
    print_matrix(result);
    return 0;
}