//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix with the given dimensions
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

// Function to perform matrix multiplication
Matrix multiply(Matrix a, Matrix b) {
    Matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = calloc(c.cols, sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            int sum = 0;
            for (int k = 0; k < a.cols; k++) {
                sum += a.data[i][k] * b.data[k][j];
            }
            c.data[i][j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
Matrix add(Matrix a, Matrix b) {
    Matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = calloc(c.cols, sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

int main() {
    Matrix a = create_matrix(3, 2);
    Matrix b = create_matrix(2, 3);
    Matrix c = add(a, b);
    Matrix d = multiply(a, b);

    // Print the matrices
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            printf("%d ", a.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < b.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            printf("%d ", b.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            printf("%d ", c.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < d.rows; i++) {
        for (int j = 0; j < d.cols; j++) {
            printf("%d ", d.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}