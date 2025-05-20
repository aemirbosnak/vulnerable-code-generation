//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3 // number of matrices
#define N 3 // number of columns in each matrix
#define MATRIX_SIZE (N * M) // size of each matrix

// Structure to represent a matrix
typedef struct {
    int *data; // pointer to array of integers representing matrix elements
    int rows; // number of rows in the matrix
    int cols; // number of columns in the matrix
} matrix_t;

// Function to initialize a matrix with random values
matrix_t *init_matrix(int size) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->data = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        mat->data[i] = rand() % 10;
    }
    mat->rows = size;
    mat->cols = size;
    return mat;
}

// Function to perform matrix multiplication
matrix_t *mult_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *result = init_matrix(a->rows * b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->rows + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
    result->rows = a->rows * b->cols;
    result->cols = b->cols;
    return result;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *result = init_matrix(a->rows * b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i * result->cols + j] = a->data[i * a->cols + j] + b->data[j * b->rows + i];
        }
    }
    result->rows = a->rows * b->cols;
    result->cols = b->cols;
    return result;
}

int main() {
    matrix_t *a = init_matrix(3);
    matrix_t *b = init_matrix(3);
    matrix_t *c = init_matrix(3);

    // Initialize matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a->data[i * 3 + j] = i * j;
            b->data[j * 3 + i] = j * i;
        }
    }

    // Perform matrix multiplication
    c = mult_matrices(a, b);

    // Print result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c->data[i * 3 + j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    c = add_matrices(a, b);

    // Print result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c->data[i * 3 + j]);
        }
        printf("\n");
    }

    return 0;
}