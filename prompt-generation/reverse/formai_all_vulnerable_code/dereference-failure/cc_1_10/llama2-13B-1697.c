//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the matrix structures
typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

// Define the matrix operations
matrix mult(matrix A, matrix B) {
    matrix C;
    int i, j, k;
    double sum;

    // Check for invalid matrix sizes
    if (A.rows != B.cols) {
        printf("Invalid matrix sizes\n");
        return C;
    }

    // Allocate memory for the result matrix
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = malloc(C.rows * C.cols * sizeof(double));

    // Perform matrix multiplication
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

    // Check for invalid matrix sizes
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Invalid matrix sizes\n");
        return C;
    }

    // Allocate memory for the result matrix
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(C.rows * C.cols * sizeof(double));

    // Perform matrix addition
    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < A.cols; j++) {
            C.data[i * C.cols + j] = A.data[i * A.cols + j] + B.data[i * B.cols + j];
        }
    }

    return C;
}

int main() {
    matrix A, B, C;
    int choice;

    // Initialize the matrices
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
            B.data[i * B.cols + j] = i * j + 1;
        }
    }

    // Ask the user for the matrix operation to perform
    printf("Enter the matrix operation to perform (1 for addition, 2 for multiplication): ");
    scanf("%d", &choice);

    // Perform the matrix operation
    if (choice == 1) {
        C = add(A, B);
    } else {
        C = mult(A, B);
    }

    // Print the result matrix
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%.2f ", C.data[i * C.cols + j]);
        }
        printf("\n");
    }

    return 0;
}