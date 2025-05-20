//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            matrix->matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    int rows_a = a->rows, cols_a = a->cols, rows_b = b->rows, cols_b = b->cols;
    matrix_t *c = init_matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            int sum = 0;
            for (int k = 0; k < cols_a; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            c->matrix[i][j] = sum;
        }
    }

    return c;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    int rows_a = a->rows, cols_a = a->cols, rows_b = b->rows, cols_b = b->cols;
    matrix_t *c = init_matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }

    return c;
}

int main() {
    matrix_t *a = init_matrix(5, 3), *b = init_matrix(4, 3), *c;

    // Perform matrix multiplication
    c = multiply_matrices(a, b);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", c->matrix[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    c = add_matrices(a, b);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", c->matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}