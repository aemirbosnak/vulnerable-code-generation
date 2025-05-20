//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MATRIX_SIZE 1024

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *m = (matrix_t *)calloc(1, sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->data = (int **)calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = (int *)calloc(m->cols, sizeof(int));
    }
    return m;
}

// Function to free a matrix
void free_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

// Function to perform matrix multiplication
matrix_t *matrix_multiply(matrix_t *a, matrix_t *b) {
    matrix_t *c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
matrix_t *matrix_add(matrix_t *a, matrix_t *b) {
    matrix_t *c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

int main() {
    matrix_t *a = new_matrix(4, 3);
    matrix_t *b = new_matrix(3, 4);
    matrix_t *c = matrix_multiply(a, b);
    matrix_t *d = matrix_add(a, b);

    // Print the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", c->data[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", d->data[i][j]);
        }
        printf("\n");
    }

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);

    return 0;
}