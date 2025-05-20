//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **elements;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.elements = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.elements[i] = calloc(cols, sizeof(int));
    }
    return m;
}

// Function to perform matrix multiplication
matrix multiply_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.elements = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.elements[i] = calloc(c.cols, sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            int sum = 0;
            for (int k = 0; k < a.cols; k++) {
                sum += a.elements[i][k] * b.elements[k][j];
            }
            c.elements[i][j] = sum;
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(2, 3);
    matrix b = create_matrix(3, 2);
    matrix c = multiply_matrices(a, b);

    // Print the result
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            printf("%d ", c.elements[i][j]);
        }
        printf("\n");
    }

    return 0;
}