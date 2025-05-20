//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
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
matrix multiply_matrices(matrix A, matrix B) {
    matrix C;
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = calloc(C.rows, sizeof(int *));
    for (int i = 0; i < C.rows; i++) {
        C.data[i] = calloc(C.cols, sizeof(int));
    }
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            int sum = 0;
            for (int k = 0; k < A.cols; k++) {
                sum += A.data[i][k] * B.data[k][j];
            }
            C.data[i][j] = sum;
        }
    }
    return C;
}

int main() {
    matrix A = create_matrix(3, 2);
    matrix B = create_matrix(2, 3);
    matrix C = multiply_matrices(A, B);
    print_matrix(C);
    return 0;
}