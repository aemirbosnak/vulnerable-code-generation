//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAGIC_NUMBER 42

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *m = malloc(sizeof(matrix_t));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(int) * rows * cols);
    return m;
}

// Function to print a matrix
void print_matrix(matrix_t *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *m1, matrix_t *m2) {
    int i, j, k;
    matrix_t *result = new_matrix(m1->rows, m2->cols);
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            int sum = m1->data[i * m1->cols + j] + m2->data[i * m2->cols + j];
            result->data[i * result->cols + j] = sum % MAGIC_NUMBER;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *m, int factor) {
    int i, j;
    matrix_t *result = new_matrix(m->rows, m->cols);
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            result->data[i * result->cols + j] = m->data[i * m->cols + j] * factor;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    matrix_t *m1 = new_matrix(10, 10);
    matrix_t *m2 = new_matrix(5, 10);

    // Initialize the matrices with some random data
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m1->data[i * m1->cols + j] = rand() % MAGIC_NUMBER;
            m2->data[i * m2->cols + j] = rand() % MAGIC_NUMBER;
        }
    }

    // Add the matrices
    matrix_t *result = add_matrices(m1, m2);

    // Print the result
    print_matrix(result);

    // Scale the result by a factor of 2
    matrix_t *scaled_result = scale_matrix(result, 2);

    // Print the scaled result
    print_matrix(scaled_result);

    return 0;
}