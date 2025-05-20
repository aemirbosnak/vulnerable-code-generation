//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: statistical
// C Matrix Operations Example Program
//
// This program demonstrates various matrix operations using C.
// It is intended to be a creative and unique example,
// showcasing the versatility and power of matrix mathematics.
//
// Compile and run without any errors!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define matrix types and operations
typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

matrix multiply(matrix A, matrix B) {
    matrix C;
    int i, j, k;
    double sum;
    
    // Calculate the product of two matrices
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = malloc(C.rows * C.cols * sizeof(double));
    
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < B.cols; j++) {
            sum = 0;
            for (k = 0; k < A.cols; k++) {
                sum += A.data[i * A.cols + k] * B.data[k * B.cols + j];
            }
            C.data[i * C.cols + j] = sum;
        }
    }
    
    return C;
}

matrix add(matrix A, matrix B) {
    matrix C;
    int i, j;
    
    // Add two matrices element-wise
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(C.rows * C.cols * sizeof(double));
    
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < A.cols; j++) {
            C.data[i * C.cols + j] = A.data[i * A.cols + j] + B.data[i * B.cols + j];
        }
    }
    
    return C;
}

matrix transpose(matrix A) {
    matrix B;
    int i, j;
    
    // Transpose a matrix
    B.rows = A.cols;
    B.cols = A.rows;
    B.data = malloc(B.rows * B.cols * sizeof(double));
    
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < A.cols; j++) {
            B.data[i * B.cols + j] = A.data[j * A.cols + i];
        }
    }
    
    return B;
}

int main() {
    matrix A, B, C;
    
    // Initialize matrices
    A.rows = 3;
    A.cols = 2;
    A.data = malloc(A.rows * A.cols * sizeof(double));
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            A.data[i * A.cols + j] = i * j;
        }
    }
    
    B.rows = 2;
    B.cols = 3;
    B.data = malloc(B.rows * B.cols * sizeof(double));
    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            B.data[i * B.cols + j] = i * j;
        }
    }
    
    // Perform matrix operations
    C = multiply(A, B);
    C = add(C, A);
    C = transpose(C);
    
    // Print results
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%.2f ", C.data[i * C.cols + j]);
        }
        printf("\n");
    }
    
    return 0;
}