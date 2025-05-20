//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(rows * cols * sizeof(int));
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = malloc(result.rows * result.cols * sizeof(int));
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, int scalar) {
    matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    result.data = malloc(result.rows * result.cols * sizeof(int));
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = scalar * m.data[i * m.cols + j];
        }
    }
    return result;
}

// Function to transpose a matrix
matrix transpose(matrix m) {
    matrix result;
    result.rows = m.cols;
    result.cols = m.rows;
    result.data = malloc(result.rows * result.cols * sizeof(int));
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m.data[j * m.cols + i];
        }
    }
    return result;
}

int main() {
    // Create two matrices
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(4, 3);

    // Print the matrices
    print_matrix(m1);
    print_matrix(m2);

    // Add the matrices
    matrix result = add_matrices(m1, m2);
    print_matrix(result);

    // Multiply the matrices
    matrix product = scalar_multiply(m1, 2);
    print_matrix(product);

    // Transpose the matrices
    matrix transposed = transpose(m1);
    print_matrix(transposed);

    return 0;
}