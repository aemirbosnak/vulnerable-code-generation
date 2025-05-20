//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a new matrix
Matrix *new_matrix(int rows, int cols) {
    Matrix *m = (Matrix *)calloc(1, sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (int *)calloc(rows * cols, sizeof(int));
    return m;
}

// Function to copy a matrix
Matrix *copy_matrix(Matrix *m) {
    Matrix *copy = new_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            copy->data[i * copy->cols + j] = m->data[i * m->cols + j];
        }
    }
    return copy;
}

// Function to transpose a matrix
Matrix *transpose_matrix(Matrix *m) {
    Matrix *transpose = new_matrix(m->cols, m->rows);
    for (int i = 0; i < m->cols; i++) {
        for (int j = 0; j < m->rows; j++) {
            transpose->data[i * transpose->rows + j] = m->data[j * m->cols + i];
        }
    }
    return transpose;
}

// Function to scale a matrix
Matrix *scale_matrix(Matrix *m, int factor) {
    Matrix *scaled = new_matrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            scaled->data[i * scaled->cols + j] = factor * m->data[i * m->cols + j];
        }
    }
    return scaled;
}

// Function to add two matrices
Matrix *add_matrices(Matrix *m1, Matrix *m2) {
    Matrix *sum = new_matrix(m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            sum->data[i * sum->cols + j] = m1->data[i * m1->cols + j] + m2->data[i * m2->cols + j];
        }
    }
    return sum;
}

int main() {
    Matrix *m1 = new_matrix(3, 4);
    Matrix *m2 = new_matrix(4, 3);
    Matrix *sum = add_matrices(m1, m2);
    printf("Sum of two matrices: \n");
    for (int i = 0; i < sum->rows; i++) {
        for (int j = 0; j < sum->cols; j++) {
            printf("%d ", sum->data[i * sum->cols + j]);
        }
        printf("\n");
    }
    return 0;
}