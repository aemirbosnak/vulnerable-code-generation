//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 10
#define COL_SIZE 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m = {rows, cols, (int **) malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * j % 10;
        }
    }
    return m;
}

// Function to perform matrix multiplication
matrix multiply(matrix A, matrix B) {
    matrix C = {A.rows, B.cols, (int **) malloc(A.rows * sizeof(int *))};
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            int sum = 0;
            for (int k = 0; k < A.cols; k++) {
                sum += A.data[i][k] * B.data[k][j];
            }
            C.data[i][j] = sum % 10;
        }
    }
    return C;
}

// Function to perform matrix addition
matrix add(matrix A, matrix B) {
    matrix C = {A.rows, B.cols, (int **) malloc(A.rows * sizeof(int *))};
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            C.data[i][j] = A.data[i][j] + B.data[i][j] % 10;
        }
    }
    return C;
}

int main() {
    matrix A = create_matrix(ROW_SIZE, COL_SIZE);
    matrix B = create_matrix(ROW_SIZE, COL_SIZE);
    matrix C = add(A, B);
    matrix D = multiply(A, B);

    printf("Matrix A:\n");
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            printf("%d ", A.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix B:\n");
    for (int i = 0; i < B.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            printf("%d ", B.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix C:\n");
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            printf("%d ", C.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix D:\n");
    for (int i = 0; i < D.rows; i++) {
        for (int j = 0; j < D.cols; j++) {
            printf("%d ", D.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}