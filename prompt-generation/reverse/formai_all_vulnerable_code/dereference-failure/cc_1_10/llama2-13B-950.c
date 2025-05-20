//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MATRIX_SIZE 5

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
    m.data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)calloc(cols, sizeof(int));
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
    result.data = (int **)calloc(result.rows, sizeof(int *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (int *)calloc(result.cols, sizeof(int));
    }
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix m1 = create_matrix(3, 4);
    Matrix m2 = create_matrix(3, 3);

    // Initialize matrix elements
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            m1.data[i][j] = i * j;
        }
    }
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            m2.data[i][j] = i * j + 10;
        }
    }

    // Add matrices
    Matrix result = add_matrices(m1, m2);

    // Print result
    print_matrix(result);

    return 0;
}