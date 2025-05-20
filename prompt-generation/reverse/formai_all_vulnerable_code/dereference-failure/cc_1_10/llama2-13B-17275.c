//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
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
    matrix m = {rows, cols, (int **) malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * j;
        }
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
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        printf("Matrix dimensions must be equal\n");
        return m1;
    }
    matrix result = create_matrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, int scalar) {
    if (m.rows == 0 || m.cols == 0) {
        return m;
    }
    matrix result = create_matrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[i][j] = m.data[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    matrix m1 = create_matrix(3, 3);
    matrix m2 = create_matrix(3, 3);
    matrix m3 = create_matrix(3, 3);

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1.data[i][j] = i * j;
            m2.data[i][j] = i + j;
            m3.data[i][j] = 0;
        }
    }

    // Add the matrices
    m3 = add_matrices(m1, m2);

    // Print the result
    print_matrix(m3);

    // Multiply the matrix by a scalar
    m3 = scalar_multiply(m3, 2);

    // Print the result
    print_matrix(m3);

    return 0;
}