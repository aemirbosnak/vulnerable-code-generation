//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = (int *)calloc(cols, sizeof(int));
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
matrix_t *matrix_multiply(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix_t *c = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
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
matrix_t *matrix_add(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix_t *c = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return c;
}

// Function to print the matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    matrix_t *a = new_matrix(3, 4);
    matrix_t *b = new_matrix(4, 3);
    matrix_t *c;

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
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
    c = matrix_multiply(a, b);

    // Print the result
    print_matrix(c);

    // Free the memory
    free_matrix(c);

    return 0;
}