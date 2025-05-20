//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *mat) {
    mat->rows = MATRIX_ROWS;
    mat->cols = MATRIX_COLS;
    mat->data = calloc(mat->rows, sizeof(int *));
    for (int i = 0; i < mat->rows; i++) {
        mat->data[i] = calloc(mat->cols, sizeof(int));
    }
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void matrix_mult(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            res->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Initialize the matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a.data[i][j] = i * j;
            b.data[i][j] = i * j + 1;
            c.data[i][j] = 0;
        }
    }

    // Add the matrices
    matrix_add(&a, &b, &c);

    // Multiply the matrices
    matrix_mult(&a, &c, &c);

    // Print the result
    print_matrix(&c);

    return 0;
}