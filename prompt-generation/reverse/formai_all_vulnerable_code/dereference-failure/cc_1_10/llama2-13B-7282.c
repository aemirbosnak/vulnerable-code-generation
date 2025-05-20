//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 13

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **elements;
} Matrix;

// Function to create a matrix
Matrix* create_matrix(int rows, int cols) {
    Matrix* matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->elements = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->elements[i] = (int*) malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to print a matrix
void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->elements[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
Matrix* multiply_matrices(Matrix* a, Matrix* b) {
    Matrix* c = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->elements[i][k] * b->elements[k][j];
            }
            c->elements[i][j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
Matrix* add_matrices(Matrix* a, Matrix* b) {
    Matrix* c = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->elements[i][j] = a->elements[i][j] + b->elements[i][j];
        }
    }
    return c;
}

int main() {
    // Create matrices
    Matrix* a = create_matrix(3, 2);
    Matrix* b = create_matrix(2, 3);
    Matrix* c;

    // Initialize matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            a->elements[i][j] = i * j + MAGIC_NUMBER;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            b->elements[i][j] = i * j + MAGIC_NUMBER;
        }
    }

    // Perform matrix multiplication
    c = multiply_matrices(a, b);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);

    // Perform matrix addition
    c = add_matrices(a, b);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);

    return 0;
}