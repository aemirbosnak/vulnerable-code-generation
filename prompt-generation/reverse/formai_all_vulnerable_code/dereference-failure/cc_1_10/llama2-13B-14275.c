//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 5
#define COL_SIZE 3

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *m = (matrix_t *)malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->matrix[i][j] = rand() % 10;
        }
    }
    return m;
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix_t *c = (matrix_t *)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        c->matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            c->matrix[i][j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix_t *c = (matrix_t *)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        c->matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return c;
}

int main() {
    matrix_t *a = new_matrix(ROW_SIZE, COL_SIZE);
    matrix_t *b = new_matrix(ROW_SIZE, COL_SIZE);
    matrix_t *c = multiply_matrices(a, b);
    matrix_t *d = add_matrices(a, b);

    // Print the results
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", c->matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", d->matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}