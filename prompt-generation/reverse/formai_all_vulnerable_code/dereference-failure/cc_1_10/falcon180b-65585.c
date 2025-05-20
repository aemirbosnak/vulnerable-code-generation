//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000

int main() {
    int i, j;
    double **A, **B, **C;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));

    A = (double **)malloc(sizeof(double *) * SIZE);
    B = (double **)malloc(sizeof(double *) * SIZE);
    C = (double **)malloc(sizeof(double *) * SIZE);

    for (i = 0; i < SIZE; i++) {
        A[i] = (double *)malloc(sizeof(double) * SIZE);
        B[i] = (double *)malloc(sizeof(double) * SIZE);
        C[i] = (double *)malloc(sizeof(double) * SIZE);

        for (j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    start = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU Time used: %lf seconds\n", cpu_time_used);

    for (i = 0; i < SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}