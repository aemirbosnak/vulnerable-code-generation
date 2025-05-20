//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

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
    matrix_t *m = (matrix_t *) malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->matrix[i] = (int *) malloc(cols * sizeof(int));
    }
    return m;
}

// Function to free the memory of a matrix
void free_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->matrix[i]);
    }
    free(m->matrix);
    free(m);
}

// Function to print the contents of a matrix
void print_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *m1, matrix_t *m2) {
    matrix_t *result = new_matrix(m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            result->matrix[i][j] = m1->matrix[i][j] + m2->matrix[j][i];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *m, int scale) {
    matrix_t *result = new_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result->matrix[i][j] = m->matrix[i][j] * scale;
        }
    }
    return result;
}

int main() {
    // Create two matrices
    matrix_t *m1 = new_matrix(3, 4);
    matrix_t *m2 = new_matrix(4, 3);

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1->matrix[i][j] = i * j;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            m2->matrix[i][j] = i * j + 1;
        }
    }

    // Add the matrices
    matrix_t *result = add_matrices(m1, m2);

    // Print the result
    print_matrix(result);

    // Scale the result by 2
    matrix_t *scaled_result = scale_matrix(result, 2);

    // Print the scaled result
    print_matrix(scaled_result);

    // Free the memory of the matrices
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(scaled_result);

    return 0;
}