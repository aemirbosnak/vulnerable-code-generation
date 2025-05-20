//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the matrix types and operations
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Matrix addition
Matrix add_matrices(Matrix A, Matrix B) {
    Matrix C;
    C.rows = A.rows;
    C.cols = B.cols;
    C.data = malloc(C.rows * C.cols * sizeof(int));
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            C.data[i * C.cols + j] = A.data[i * A.cols + j] + B.data[i * B.cols + j];
        }
    }
    return C;
}

// Matrix multiplication
Matrix mult_matrices(Matrix A, Matrix B) {
    Matrix C;
    C.rows = A.cols;
    C.cols = B.rows;
    C.data = malloc(C.rows * C.cols * sizeof(int));
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            int sum = 0;
            for (int k = 0; k < A.cols; k++) {
                sum += A.data[i * A.cols + k] * B.data[k * B.rows + j];
            }
            C.data[i * C.cols + j] = sum;
        }
    }
    return C;
}

// Matrix transpose
Matrix transpose_matrix(Matrix A) {
    Matrix B;
    B.rows = A.cols;
    B.cols = A.rows;
    B.data = malloc(B.rows * B.cols * sizeof(int));
    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            B.data[i * B.cols + j] = A.data[j * A.rows + i];
        }
    }
    return B;
}

int main() {
    Matrix A = {3, 2, {1, 2, 3, 4, 5}};
    Matrix B = {2, 2, {2, 3, 4, 5, 6}};
    Matrix C = add_matrices(A, B);
    printf("Matrix C = ");
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%d ", C.data[i * C.cols + j]);
        }
        printf("\n");
    }
    printf("\n");

    Matrix D = mult_matrices(A, B);
    printf("Matrix D = ");
    for (int i = 0; i < D.rows; i++) {
        for (int j = 0; j < D.cols; j++) {
            printf("%d ", D.data[i * D.cols + j]);
        }
        printf("\n");
    }
    printf("\n");

    Matrix E = transpose_matrix(A);
    printf("Matrix E = ");
    for (int i = 0; i < E.rows; i++) {
        for (int j = 0; j < E.cols; j++) {
            printf("%d ", E.data[i * E.cols + j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}