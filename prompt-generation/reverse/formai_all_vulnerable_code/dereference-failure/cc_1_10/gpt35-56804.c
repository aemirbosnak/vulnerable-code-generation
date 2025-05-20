//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main()
{
    int i, j, k;
    double **A, **B, **C;
    clock_t start, end;
    double elapsed_time;

    // allocate memory for matrices A, B, and C
    A = (double **) malloc(N * sizeof(double *));
    B = (double **) malloc(N * sizeof(double *));
    C = (double **) malloc(N * sizeof(double *));
    for (i = 0; i < N; i++) {
        A[i] = (double *) malloc(N * sizeof(double));
        B[i] = (double *) malloc(N * sizeof(double));
        C[i] = (double *) malloc(N * sizeof(double));
    }

    // initialize matrices A and B with random values
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = (double) rand() / RAND_MAX;
            B[i][j] = (double) rand() / RAND_MAX;
        }
    }

    // perform matrix multiplication and time the operation
    start = clock();
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print the result and elapsed time
    printf("Result:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }
    printf("Elapsed time: %.4f seconds\n", elapsed_time);

    // free memory
    for (i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}