//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = calloc(cols, sizeof(int));
    }
}

void print_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void multiply_matrix(matrix_t *a, matrix_t *b, matrix_t *res) {
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
    matrix_t a, b, res;
    init_matrix(&a, 3, 3);
    init_matrix(&b, 3, 3);
    init_matrix(&res, 3, 3);

    // Initialize matrix A
    a.data[0][0] = 1; a.data[0][1] = 2; a.data[0][2] = 3;
    a.data[1][0] = 4; a.data[1][1] = 5; a.data[1][2] = 6;
    a.data[2][0] = 7; a.data[2][1] = 8; a.data[2][2] = 9;

    // Initialize matrix B
    b.data[0][0] = 10; b.data[0][1] = 11; b.data[0][2] = 12;
    b.data[1][0] = 13; b.data[1][1] = 14; b.data[1][2] = 15;
    b.data[2][0] = 16; b.data[2][1] = 17; b.data[2][2] = 18;

    // Add matrices A and B
    add_matrix(&a, &b, &res);

    // Print result
    print_matrix(&res);

    // Multiply matrices A and B
    multiply_matrix(&a, &b, &res);

    // Print result
    print_matrix(&res);

    return 0;
}