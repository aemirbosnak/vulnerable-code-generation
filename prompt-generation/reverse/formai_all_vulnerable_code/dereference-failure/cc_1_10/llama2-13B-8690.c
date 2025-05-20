//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 7

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix
Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
    }
    return m;
}

// Function to print a matrix
void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(Matrix m1, Matrix m2) {
    Matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = calloc(result.rows, sizeof(int *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = calloc(result.cols, sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix scalar_multiply(Matrix m, int scalar) {
    Matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    result.data = calloc(result.rows, sizeof(int *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = calloc(result.cols, sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = scalar * m.data[i][j];
        }
    }
    return result;
}

int main() {
    Matrix m1 = create_matrix(ROWS, COLS);
    Matrix m2 = create_matrix(ROWS, COLS);
    Matrix result;

    // Initialize matrix elements
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            m1.data[i][j] = i * j;
            m2.data[i][j] = i * j * 2;
        }
    }

    // Add matrices
    result = add_matrices(m1, m2);

    // Print result
    print_matrix(result);

    // Multiply matrix by scalar
    result = scalar_multiply(result, 3);

    // Print result
    print_matrix(result);

    return 0;
}