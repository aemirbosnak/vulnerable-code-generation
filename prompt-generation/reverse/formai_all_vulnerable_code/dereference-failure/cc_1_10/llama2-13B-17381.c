//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
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
    matrix m = {rows, cols, NULL};
    int i, j;

    for (i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
        for (j = 0; j < cols; j++) {
            m.data[i][j] = i * j;
        }
    }

    return m;
}

// Function to perform matrix multiplication
matrix multiply(matrix A, matrix B) {
    int i, j, k;
    matrix C = {A.rows, B.cols, NULL};

    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < B.cols; j++) {
            C.data[i][j] = 0;
            for (k = 0; k < A.cols; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }

    return C;
}

// Function to perform matrix addition
matrix add(matrix A, matrix B) {
    int i, j;
    matrix C = {A.rows, B.cols, NULL};

    for (i = 0; i < A.rows; i++) {
        for (j = 0; j < B.cols; j++) {
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }

    return C;
}

int main() {
    matrix A = create_matrix(3, 2);
    matrix B = create_matrix(2, 3);
    matrix C = multiply(A, B);
    matrix D = add(A, B);

    printf("Matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", A.data[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Matrix B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", B.data[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Matrix C:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", C.data[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Matrix D:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", D.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}