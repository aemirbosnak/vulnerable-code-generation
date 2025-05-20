//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to create a new matrix
matrix *create_matrix(int rows, int cols) {
    matrix *m = (matrix *)malloc(sizeof(matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (int *)malloc(sizeof(int) * rows * cols);
    return m;
}

// Function to free memory allocated by create_matrix
void free_matrix(matrix *m) {
    free(m->data);
    free(m);
}

// Function to print a matrix
void print_matrix(matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix *add_matrices(matrix *m1, matrix *m2) {
    int i, j, k;
    matrix *result = create_matrix(m1->rows, m2->cols);
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            for (k = 0; k < m1->cols; k++) {
                result->data[i * result->cols + j] += m1->data[i * m1->cols + k] + m2->data[k * m2->cols + j];
            }
        }
    }
    return result;
}

// Function to subtract a matrix from another
matrix *subtract_matrices(matrix *m1, matrix *m2) {
    int i, j, k;
    matrix *result = create_matrix(m1->rows, m2->cols);
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            for (k = 0; k < m1->cols; k++) {
                result->data[i * result->cols + j] -= m1->data[i * m1->cols + k] - m2->data[k * m2->cols + j];
            }
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix *scale_matrix(matrix *m, int factor) {
    int i, j;
    matrix *result = create_matrix(m->rows, m->cols);
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            result->data[i * result->cols + j] = m->data[i * m->cols + j] * factor;
        }
    }
    return result;
}

int main() {
    matrix *m1 = create_matrix(3, 3);
    matrix *m2 = create_matrix(3, 3);
    matrix *result;

    // Initialize matrix elements
    m1->data[0 * m1->cols + 0] = 1;
    m1->data[0 * m1->cols + 1] = 2;
    m1->data[0 * m1->cols + 2] = 3;
    m1->data[1 * m1->cols + 0] = 4;
    m1->data[1 * m1->cols + 1] = 5;
    m1->data[1 * m1->cols + 2] = 6;
    m1->data[2 * m1->cols + 0] = 7;
    m1->data[2 * m1->cols + 1] = 8;
    m1->data[2 * m1->cols + 2] = 9;

    m2->data[0 * m2->cols + 0] = 10;
    m2->data[0 * m2->cols + 1] = 11;
    m2->data[0 * m2->cols + 2] = 12;
    m2->data[1 * m2->cols + 0] = 13;
    m2->data[1 * m2->cols + 1] = 14;
    m2->data[1 * m2->cols + 2] = 15;
    m2->data[2 * m2->cols + 0] = 16;
    m2->data[2 * m2->cols + 1] = 17;
    m2->data[2 * m2->cols + 2] = 18;

    // Perform matrix operations
    result = add_matrices(m1, m2);
    print_matrix(result);

    result = subtract_matrices(m1, m2);
    print_matrix(result);

    result = scale_matrix(m1, 2);
    print_matrix(result);

    free_matrix(m1);
    free_matrix(m2);
    free_matrix(result);

    return 0;
}