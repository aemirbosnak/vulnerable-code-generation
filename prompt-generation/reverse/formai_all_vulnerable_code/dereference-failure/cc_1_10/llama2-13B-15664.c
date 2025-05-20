//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: authentic
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
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
    }
    return m;
}

// Function to perform matrix multiplication
matrix multiply(matrix A, matrix B) {
    matrix C;
    int i, j, k;
    
    // Check if the matrices have the same dimensions
    if (A.rows != B.cols) {
        printf("Error: Matrices must have the same dimensions\n");
        return C;
    }
    
    // Allocate memory for the result matrix
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = calloc(C.rows, sizeof(int *));
    
    // Initialize the result matrix with 0s
    for (i = 0; i < C.rows; i++) {
        C.data[i] = calloc(C.cols, sizeof(int));
    }
    
    // Perform matrix multiplication
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < B.cols; j++) {
            for (k = 0; k < A.cols; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    
    return C;
}

// Example usage
int main() {
    matrix A = create_matrix(2, 3);
    matrix B = create_matrix(3, 2);
    matrix C = multiply(A, B);
    
    // Print the result matrix
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%d ", C.data[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}