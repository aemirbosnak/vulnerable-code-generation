//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
#define M 3

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a matrix
Matrix createMatrix(int r, int c) {
    Matrix m;
    m.rows = r;
    m.cols = c;
    m.data = (int *)malloc(r * c * sizeof(int));
    return m;
}

// Function to print a matrix
void printMatrix(Matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    int i, j, k;
    C.rows = A.rows * B.cols;
    C.cols = A.cols;
    C.data = (int *)malloc(C.rows * C.cols * sizeof(int));
    for (i = 0; i < C.rows; i++) {
        for (j = 0; j < C.cols; j++) {
            for (k = 0; k < A.rows; k++) {
                C.data[i * C.cols + j] += A.data[i * A.cols + k] * B.data[k * B.cols + j];
            }
        }
    }
    return C;
}

// Function to perform matrix addition
Matrix add(Matrix A, Matrix B) {
    Matrix C;
    int i, j;
    C.rows = A.rows + B.rows;
    C.cols = A.cols;
    C.data = (int *)malloc(C.rows * C.cols * sizeof(int));
    for (i = 0; i < C.rows; i++) {
        for (j = 0; j < C.cols; j++) {
            C.data[i * C.cols + j] = A.data[i * A.cols + j] + B.data[i * B.cols + j];
        }
    }
    return C;
}

int main() {
    srand(time(NULL));

    // Create two matrices
    Matrix A = createMatrix(N, M);
    Matrix B = createMatrix(N, M);

    // Initialize matrix elements with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A.data[i * A.cols + j] = rand() % 10;
            B.data[i * B.cols + j] = rand() % 10;
        }
    }

    // Perform matrix multiplication and addition
    Matrix C = multiply(A, B);
    Matrix D = add(A, B);

    // Print the results
    printMatrix(C);
    printMatrix(D);

    return 0;
}