//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add_matrices(int m, int n, int **A, int **B, int **C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int m, int n, int **A, int **B, int **C) {
    int m1 = m, n1 = n, m2 = m;
    if (m!= n) {
        m1 = n;
        n1 = m;
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            for (int k = 0; k < m2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m = 3, n = 3;
    int **A, **B, **C;
    A = (int **)malloc(m * sizeof(int *));
    B = (int **)malloc(m * sizeof(int *));
    C = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        B[i] = (int *)malloc(n * sizeof(int));
        C[i] = (int *)malloc(n * sizeof(int));
    }

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    B[0][0] = 4; B[0][1] = 5; B[0][2] = 6;
    C[0][0] = 7; C[0][1] = 8; C[0][2] = 9;

    add_matrices(m, n, A, B, C);
    printf("Matrix A + Matrix B = \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    multiply_matrices(m, n, A, B, C);
    printf("Matrix A * Matrix B = \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    free(A); free(B); free(C);
    return 0;
}