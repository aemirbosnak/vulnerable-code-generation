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

void matrix_init(matrix_t *mat) {
    mat->rows = MATRIX_ROWS;
    mat->cols = MATRIX_COLS;
    mat->data = calloc(MATRIX_ROWS, sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        mat->data[i] = calloc(MATRIX_COLS, sizeof(int));
    }
}

void matrix_print(matrix_t *mat) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void matrix_multiply(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < MATRIX_ROWS; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            a->data[i][j] = sum;
        }
    }
}

int main() {
    srand(time(NULL));

    matrix_t mat1, mat2, res;

    matrix_init(&mat1);
    matrix_init(&mat2);
    matrix_init(&res);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            int value = rand() % 10;
            mat1.data[i][j] = value;
            mat2.data[i][j] = value;
        }
    }

    matrix_add(&mat1, &mat2);
    matrix_multiply(&mat1, &mat2);

    matrix_print(&res);

    return 0;
}