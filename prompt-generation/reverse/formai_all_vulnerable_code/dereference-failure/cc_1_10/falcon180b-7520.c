//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int n;
    double **A, **B, **C;
    int *ipiv;
    double alpha = 1.0;
    double beta = 0.0;

    srand(time(0));
    n = rand() % MAX_SIZE + 1;
    A = (double **)malloc(n * sizeof(double *));
    B = (double **)malloc(n * sizeof(double *));
    C = (double **)malloc(n * sizeof(double *));
    ipiv = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        B[i] = (double *)malloc(n * sizeof(double));
        C[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10 - 5;
            B[i][j] = rand() % 10 - 5;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0.0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += alpha * A[i][k] * B[k][j] + beta * C[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
        free(ipiv[i]);
    }

    free(A);
    free(B);
    free(C);
    free(ipiv);

    return 0;
}