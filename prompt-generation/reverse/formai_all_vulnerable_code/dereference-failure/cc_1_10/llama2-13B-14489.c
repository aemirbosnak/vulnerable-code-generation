//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 3

// Define a structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to create a new matrix
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
    int i, j;
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m2.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix scale_matrix(matrix m, int factor) {
    matrix result;
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            result.data[i * result.cols + j] = m.data[i * m.cols + j] * factor;
        }
    }
    return result;
}

int main() {
    matrix m1 = create_matrix(M, N);
    matrix m2 = create_matrix(N, N);
    matrix m3 = create_matrix(M, N);

    // Initialize matrix data
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            m1.data[i * m1.cols + j] = i * j;
        }
    }

    // Add two matrices
    m3 = add_matrices(m1, m2);

    // Scale matrix by a factor
    m3 = scale_matrix(m3, 2);

    // Print the result
    print_matrix(m3);

    return 0;
}