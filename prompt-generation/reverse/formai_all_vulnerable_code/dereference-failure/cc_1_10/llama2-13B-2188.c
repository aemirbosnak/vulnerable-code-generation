//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *m = malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->matrix[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
    }
    return m;
}

// Function to print a matrix
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
            result->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t *m1 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *m2 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = add_matrices(m1, m2);
    print_matrix(result);
    free(result);
    free(m1);
    free(m2);
    return 0;
}