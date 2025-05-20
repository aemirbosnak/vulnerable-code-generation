//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

void matrix_init(matrix_t *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = calloc(rows * cols, sizeof(int));
}

void matrix_free(matrix_t *mat) {
    free(mat->data);
}

void matrix_print(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *matrix_multiply(matrix_t *a, matrix_t *b) {
    matrix_t *c = malloc(sizeof(matrix_t));
    int i, j, k;
    
    // Initialize c matrix
    c->rows = a->rows * b->cols;
    c->cols = a->cols * b->rows;
    c->data = malloc(c->rows * c->cols * sizeof(int));
    
    // Multiply matrices
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->rows + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }
    
    return c;
}

int main() {
    matrix_t *a, *b, *c;
    
    // Initialize matrices
    matrix_init(a, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(b, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(c, MATRIX_ROWS, MATRIX_COLS);
    
    // Fill matrices with data
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i * MATRIX_COLS + j] = i * j;
            b->data[i * MATRIX_COLS + j] = i + j;
            c->data[i * MATRIX_COLS + j] = 0;
        }
    }
    
    // Multiply matrices
    c = matrix_multiply(a, b);
    
    // Print results
    matrix_print(c);
    
    // Free matrices
    matrix_free(a);
    matrix_free(b);
    matrix_free(c);
    
    return 0;
}