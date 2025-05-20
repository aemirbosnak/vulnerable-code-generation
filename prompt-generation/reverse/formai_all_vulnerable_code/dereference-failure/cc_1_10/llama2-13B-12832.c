//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *) malloc(cols * sizeof(int));
    }
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = (int **) malloc(result.rows * sizeof(int *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (int *) malloc(result.cols * sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, int scalar) {
    matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    result.data = (int **) malloc(result.rows * sizeof(int *));
    for (int i = 0; i < result.rows; i++) {
        result.data[i] = (int *) malloc(result.cols * sizeof(int));
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = m.data[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(3, 3);
    matrix result;

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i][j] = i * j;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m2.data[i][j] = i * j;
        }
    }

    // Add the matrices
    result = add_matrices(m1, m2);
    print_matrix(result);

    // Multiply the matrix by a scalar
    result = scalar_multiply(m1, 2);
    print_matrix(result);

    return 0;
}