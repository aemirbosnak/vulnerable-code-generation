//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
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
    matrix m = {rows, cols, malloc(rows * cols * sizeof(int))};
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    matrix result = create_matrix(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i][j] = m1.data[i][0] + m2.data[0][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, int scalar) {
    matrix result = create_matrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[i][j] = m.data[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(4, 3);
    matrix result = add_matrices(m1, m2);
    print_matrix(result);

    m1 = create_matrix(3, 4);
    m2 = create_matrix(4, 3);
    result = scalar_multiply(m1, 2);
    print_matrix(result);

    return 0;
}