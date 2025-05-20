//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void matrix_init(matrix_t *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = rand() % 10;
        }
    }
}

void matrix_print(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *mat1, matrix_t *mat2) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            mat1->data[i][j] += mat2->data[i][j];
        }
    }
}

void matrix_multiply(matrix_t *mat1, matrix_t *mat2) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat2->rows; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            mat1->data[i][j] = sum;
        }
    }
}

int main() {
    srand(time(NULL));

    matrix_t mat1, mat2, mat3;
    matrix_init(&mat1, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&mat2, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&mat3, MATRIX_ROWS, MATRIX_COLS);

    matrix_print(&mat1);
    matrix_print(&mat2);

    matrix_add(&mat1, &mat2);
    matrix_print(&mat1);

    matrix_multiply(&mat1, &mat2);
    matrix_print(&mat3);

    return 0;
}