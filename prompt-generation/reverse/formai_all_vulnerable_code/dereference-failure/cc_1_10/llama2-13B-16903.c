//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double *)calloc(rows * cols, sizeof(double));
    return m;
}

// Function to multiply two matrices
Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    int i, j, k;

    // Check for invalid matrix sizes
    if (A.rows != B.cols) {
        printf("Invalid matrix sizes\n");
        return C;
    }

    // Allocate memory for the result matrix
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = (double *)calloc(C.rows * C.cols, sizeof(double));

    // Loop over rows of A and columns of B
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < B.cols; j++) {
            double sum = 0;

            // Loop over elements of A and B
            for (k = 0; k < A.cols; k++) {
                sum += A.data[i * A.cols + k] * B.data[k * B.rows + j];
            }

            C.data[i * C.cols + j] = sum;
        }
    }

    return C;
}

// Example usage
int main() {
    Matrix A = createMatrix(2, 3);
    Matrix B = createMatrix(3, 2);
    Matrix C = multiply(A, B);

    // Print the result matrix
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%.2f ", C.data[i * C.cols + j]);
        }
        printf("\n");
    }

    return 0;
}