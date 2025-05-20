//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int m, n;
    float *mat;
} Matrix;

/* Function to initialize a matrix */
Matrix initializeMatrix(int m, int n) {
    Matrix matrix;
    matrix.m = m;
    matrix.n = n;
    matrix.mat = (float*)malloc(m * n * sizeof(float));
    return matrix;
}

/* Function to print a matrix */
void printMatrix(Matrix matrix) {
    int i, j;
    for (i = 0; i < matrix.m; i++) {
        for (j = 0; j < matrix.n; j++) {
            printf("%f ", matrix.mat[i * matrix.n + j]);
        }
        printf("\n");
    }
}

/* Function to perform matrix multiplication */
void matrixMultiplication(Matrix a, Matrix b, Matrix c) {
    int i, j, k;
    for (i = 0; i < a.m; i++) {
        for (j = 0; j < b.n; j++) {
            for (k = 0; k < c.n; k++) {
                c.mat[i * c.n + k] += a.mat[i * a.n + j] * b.mat[j * b.n + k];
            }
        }
    }
}

/* Function to perform matrix inversion */
void matrixInversion(Matrix a, Matrix b) {
    int i, j, k, l;
    Matrix temp;
    temp = initializeMatrix(a.m, a.n);
    for (i = 0; i < a.m; i++) {
        for (j = 0; j < a.n; j++) {
            temp.mat[i * a.n + j] = a.mat[j * a.n + i];
        }
    }
    for (k = 0; k < a.n; k++) {
        for (l = 0; l < a.n; l++) {
            if (k == l) {
                temp.mat[k * a.n + l] = 1;
            }
            else {
                temp.mat[k * a.n + l] = 0;
            }
        }
    }
    for (i = 0; i < a.m; i++) {
        for (j = 0; j < a.n; j++) {
            b.mat[i * a.n + j] = temp.mat[j * a.n + i];
        }
    }
}

/* Function to print the result of matrix multiplication */
void printResult(Matrix a, Matrix b, Matrix c) {
    printMatrix(a);
    printf("*\n");
    printMatrix(b);
    printf("= \n");
    printMatrix(c);
}

/* Function to print the result of matrix inversion */
void printResultInverse(Matrix a, Matrix b) {
    printMatrix(a);
    printf("\nInverse of A =\n");
    printMatrix(b);
}

/* Driver program to test the matrix multiplication and inversion */
int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    Matrix A = initializeMatrix(n, n);
    Matrix B = initializeMatrix(n, n);
    Matrix C = initializeMatrix(n, n);
    Matrix D = initializeMatrix(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the elements of matrix A: ");
            scanf("%f", &A.mat[i * n + j]);
            printf("Enter the elements of matrix B: ");
            scanf("%f", &B.mat[i * n + j]);
        }
    }

    matrixMultiplication(A, B, C);
    printResult(A, B, C);

    matrixInversion(A, D);
    printResultInverse(A, D);

    free(A.mat);
    free(B.mat);
    free(C.mat);
    free(D.mat);

    return 0;
}