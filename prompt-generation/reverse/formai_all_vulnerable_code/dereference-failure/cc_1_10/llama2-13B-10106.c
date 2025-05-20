//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *matrix) {
    matrix->rows = MATRIX_ROWS;
    matrix->cols = MATRIX_COLS;
    matrix->data = malloc(MATRIX_ROWS * sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        matrix->data[i] = malloc(MATRIX_COLS * sizeof(int));
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix->data[i][j] = rand() % 10;
        }
    }
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void secure_addition(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

int main() {
    matrix_t a, b, c;

    srand(time(NULL));

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    secure_addition(&a, &b, &c);

    print_matrix(&c);

    return 0;
}