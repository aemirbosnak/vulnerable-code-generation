//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void matrix_init(matrix_t *mat) {
    mat->rows = MATRIX_ROWS;
    mat->cols = MATRIX_COLS;
    mat->matrix = malloc(MATRIX_ROWS * sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        mat->matrix[i] = malloc(MATRIX_COLS * sizeof(int));
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat->matrix[i][j] = rand() % 10;
        }
    }
}

void matrix_print(matrix_t *mat) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *mat1, matrix_t *mat2) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1->matrix[i][j] += mat2->matrix[i][j];
        }
    }
}

int main() {
    matrix_t mat1, mat2, result;

    srand(time(NULL));

    matrix_init(&mat1);
    matrix_init(&mat2);

    matrix_print(&mat1);
    matrix_print(&mat2);

    matrix_add(&mat1, &mat2);

    matrix_print(&result);

    return 0;
}