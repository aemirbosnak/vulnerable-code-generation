//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **elements;
} Matrix;

// Function to create a matrix
Matrix create_matrix(int rows, int cols) {
    Matrix m = {rows, cols, (int **) malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.elements[i] = (int *) malloc(cols * sizeof(int));
    }
    return m;
}

// Function to print a matrix
void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.elements[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(Matrix m1, Matrix m2) {
    Matrix result = create_matrix(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            int sum = m1.elements[i][j] + m2.elements[i][j];
            result.elements[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix scalar_multiply(Matrix m, int scalar) {
    Matrix result = create_matrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.elements[i][j] = m.elements[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    Matrix m1 = create_matrix(3, 4);
    Matrix m2 = create_matrix(3, 2);
    Matrix m3 = create_matrix(3, 4);

    // Initialize elements of m1 and m2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.elements[i][j] = i * j;
            m2.elements[i][j] = i * (j + 1);
        }
    }

    // Add m1 and m2
    Matrix result = add_matrices(m1, m2);
    print_matrix(result);

    // Multiply m1 by 2
    result = scalar_multiply(m1, 2);
    print_matrix(result);

    return 0;
}