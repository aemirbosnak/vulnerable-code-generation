//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 6

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            a->matrix[i][j] += b->matrix[i][j];
        }
    }
}

void multiply_matrices(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            a->matrix[i][j] = sum;
        }
    }
}

int main() {
    matrix_t *a = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    // Initialize matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->matrix[i][j] = i * j;
            b->matrix[i][j] = i + j;
        }
    }

    // Add matrices
    add_matrices(a, b);

    // Multiply matrices
    multiply_matrices(a, b);

    // Print result
    print_matrix(c);

    return 0;
}