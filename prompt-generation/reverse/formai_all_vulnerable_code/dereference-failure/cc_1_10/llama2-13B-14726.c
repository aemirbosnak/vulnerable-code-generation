//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *c = create_matrix(a->rows, b->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *c = create_matrix(a->rows, a->cols);
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
    return c;
}

int main() {
    matrix_t *a, *b, *c;

    // Create matrix A
    a = create_matrix(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            a->data[i * 4 + j] = i * j;
        }
    }

    // Create matrix B
    b = create_matrix(3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            b->data[i * 4 + j] = i * j + 1;
        }
    }

    // Perform matrix multiplication
    c = multiply_matrices(a, b);

    // Print the result
    print_matrix(c);

    // Perform matrix addition
    c = add_matrices(a, b);

    // Print the result
    print_matrix(c);

    return 0;
}