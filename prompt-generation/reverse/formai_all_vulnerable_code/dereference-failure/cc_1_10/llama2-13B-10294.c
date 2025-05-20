//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to free the memory of a matrix
void free_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->matrix[i]);
    }
    free(mat->matrix);
    free(mat);
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    int rows_a = a->rows;
    int cols_a = a->cols;
    int rows_b = b->rows;
    int cols_b = b->cols;

    matrix_t *c = new_matrix(rows_a, cols_b);

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
    int rows_a = a->rows;
    int cols_a = a->cols;
    int rows_b = b->rows;
    int cols_b = b->cols;

    matrix_t *c = new_matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }

    return c;
}

int main() {
    matrix_t *a = new_matrix(5, 4);
    matrix_t *b = new_matrix(4, 3);
    matrix_t *c;

    // Initialize the elements of A and B
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            a->matrix[i][j] = i * j;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            b->matrix[i][j] = i * j;
        }
    }

    // Perform matrix multiplication
    c = multiply_matrices(a, b);

    // Print the result
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c->matrix[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    c = add_matrices(a, b);

    // Print the result
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c->matrix[i][j]);
        }
        printf("\n");
    }

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    return 0;
}