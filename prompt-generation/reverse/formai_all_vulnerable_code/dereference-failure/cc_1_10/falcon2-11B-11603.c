//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add_matrices(int** A, int** B, int** C, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to multiply a matrix by a scalar
void multiply_scalar(int** A, int** B, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j] * B[i][j];
        }
    }
}

// Function to transpose a matrix
void transpose(int** A, int** B, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[j][i] = A[i][j];
        }
    }
}

// Function to calculate the determinant of a matrix
int det(int** A, int m) {
    int determinant = 0;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += A[i][j] * ((j + 1) % m);
        }
        determinant += (m - i) * sum;
    }
    return determinant;
}

// Main function
int main() {
    int m = 3, n = 3;
    int** A = (int**)malloc(m * sizeof(int*));
    int** B = (int**)malloc(m * sizeof(int*));
    int** C = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        B[i] = (int*)malloc(n * sizeof(int));
        C[i] = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    printf("Matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    add_matrices(A, B, C, m, n);
    printf("Matrix C = A + B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    multiply_scalar(A, B, m, n);
    printf("Matrix B = 2 * A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    transpose(A, B, m, n);
    printf("Matrix B = transpose(A):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[j][i]);
        }
        printf("\n");
    }

    int det_A = det(A, m);
    printf("Determinant of A = %d\n", det_A);

    free(A);
    free(B);
    free(C);

    return 0;
}