//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a new matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
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

// Function to perform matrix multiplication
matrix multiply_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = calloc(c.cols, sizeof(int));
    }
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

// Function to perform matrix addition
matrix add_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = calloc(c.cols, sizeof(int));
    }
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(3, 3);
    matrix b = create_matrix(3, 3);
    matrix c;

    // Initialize matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a.data[i][j] = i * j;
            b.data[i][j] = i * j + 1;
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
    print_matrix(c);

    return 0;
}