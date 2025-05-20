//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
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

// Function to create a new matrix
matrix_t* new_matrix(int rows, int cols) {
    matrix_t* m = (matrix_t*)malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return m;
}

// Function to free the memory of a matrix
void free_matrix(matrix_t* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->matrix[i]);
    }
    free(m->matrix);
    free(m);
}

// Function to perform matrix multiplication
matrix_t* matrix_multiply(matrix_t* a, matrix_t* b) {
    matrix_t* c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
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
matrix_t* matrix_add(matrix_t* a, matrix_t* b) {
    matrix_t* c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return c;
}

// Function to print the contents of a matrix
void print_matrix(matrix_t* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    matrix_t* a = new_matrix(3, 4);
    matrix_t* b = new_matrix(4, 3);
    matrix_t* c;

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

    // Free the memory of the matrices
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    return 0;
}