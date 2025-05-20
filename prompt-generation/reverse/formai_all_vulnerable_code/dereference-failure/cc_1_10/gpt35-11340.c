//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void matrixMultiplication(int n){
    int **A, **B, **C;

    A = (int **) malloc( n * sizeof(int *) );
    B = (int **) malloc( n * sizeof(int *) );
    C = (int **) malloc( n * sizeof(int *) );

    for (int i = 0; i < n * n; i++){
        A[i] = (int *) malloc( n * sizeof(int) );
        B[i] = (int *) malloc( n * sizeof(int) );
        C[i] = (int *) malloc( n * sizeof(int) );
    }

    for (int i = 0; i < n * n; i++){
        A[i/n][i%n] = rand() % 10;
        B[i/n][i%n] = rand() % 10;
        C[i/n][i%n] = 0;
    }

    clock_t start = clock();

    // Matrix Multiplication
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    
    printf("\n******************************************************************************");
    printf("\nMatrix multiplication of size %d took %f seconds to process.\n", n, time_taken);
    printf("******************************************************************************\n");

    free(A);
    free(B);
    free(C);
}

int main() {
    int n = 1000;
    matrixMultiplication(n);
    return 0;
}