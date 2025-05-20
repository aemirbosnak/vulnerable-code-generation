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
    int **matrix;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void add_matrix(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = a->cols;
    matrix_t *c = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }

    print_matrix(c);
    free_matrix(c);
}

void multiply_matrix(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix_t *c = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            c->matrix[i][j] = sum;
        }
    }

    print_matrix(c);
    free_matrix(c);
}

int main() {
    srand(time(NULL));

    matrix_t *a = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c;

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->matrix[i][j] = rand() % 10;
            b->matrix[i][j] = rand() % 10;
        }
    }

    add_matrix(a, b);
    multiply_matrix(a, b);

    return 0;
}