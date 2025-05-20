//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to initialize a matrix with random values
matrix init_matrix(int rows, int cols) {
    matrix m = {rows, cols, (int **) malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = rand() % 10 - 5;
        }
    }
    return m;
}

// Function to perform matrix multiplication
matrix multiply_matrices(matrix A, matrix B) {
    matrix C = {A.rows, B.cols, (int **) malloc(A.rows * sizeof(int *))};
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

// Function to perform matrix addition
matrix add_matrices(matrix A, matrix B) {
    matrix C = {A.rows, B.cols, (int **) malloc(A.rows * sizeof(int *))};
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return C;
}

int main() {
    matrix A = init_matrix(3, 4);
    matrix B = init_matrix(4, 3);
    matrix C = add_matrices(A, B);
    matrix D = multiply_matrices(A, B);

    // Print the results
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            printf("%d ", C.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < D.rows; i++) {
        for (int j = 0; j < D.cols; j++) {
            printf("%d ", D.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}