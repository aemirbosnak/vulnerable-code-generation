//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)calloc(cols, sizeof(int));
    }
    return matrix;
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    int rows_a = a->rows;
    int cols_a = a->cols;
    int rows_b = b->rows;
    int cols_b = b->cols;
    matrix_t *result = create_matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            int sum = 0;
            for (int k = 0; k < cols_a; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }

    return result;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    int rows_a = a->rows;
    int cols_a = a->cols;
    int rows_b = b->rows;
    int cols_b = b->cols;
    matrix_t *result = create_matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

int main() {
    matrix_t *a = create_matrix(3, 3);
    matrix_t *b = create_matrix(3, 3);
    matrix_t *c;

    // Initialize matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a->data[i][j] = i * j;
            b->data[i][j] = i * j + 1;
        }
    }

    // Perform matrix multiplication
    c = multiply_matrices(a, b);

    // Print result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c->data[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    c = add_matrices(a, b);

    // Print result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}