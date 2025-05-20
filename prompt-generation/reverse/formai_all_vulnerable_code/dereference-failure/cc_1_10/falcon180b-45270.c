//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000
#define M 10

int main() {
    int i, j, k;
    int *a, *b, *c;
    clock_t start, end;

    // Allocate memory for arrays
    a = (int *)malloc(N * sizeof(int));
    b = (int *)malloc(N * sizeof(int));
    c = (int *)malloc(N * sizeof(int));

    // Initialize arrays with random values
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    start = clock();

    // Perform matrix multiplication
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            for (k = 0; k < M; k++) {
                c[i * M + j] += a[i * M + k] * b[k * M + j];
            }
        }
    }

    end = clock();

    // Print the result
    printf("The result of matrix multiplication is:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", c[i * M + j]);
        }
        printf("\n");
    }

    // Free memory
    free(a);
    free(b);
    free(c);

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}