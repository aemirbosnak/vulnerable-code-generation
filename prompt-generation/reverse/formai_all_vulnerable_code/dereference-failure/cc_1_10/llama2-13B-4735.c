//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

void print_matrix(matrix_t *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *create_random_matrix(int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int) * rows * cols);
    for (int i = 0; i < rows * cols; i++) {
        matrix->data[i] = rand() % 10;
    }
    return matrix;
}

matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *result = create_random_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    matrix_t *a = create_random_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_random_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = multiply_matrices(a, b);
    print_matrix(result);
    free(result);
    free(a);
    free(b);
    return 0;
}