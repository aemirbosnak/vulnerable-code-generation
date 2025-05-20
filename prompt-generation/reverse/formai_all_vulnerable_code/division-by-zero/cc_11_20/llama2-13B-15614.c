//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 3

int main() {
    int i, j, k;
    int a[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    int b[M][N] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int c[M][N];

    // Matrix addition
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // Matrix multiplication
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Matrix transpose
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = a[i][j];
        }
    }

    // Matrix inverse
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = a[i][j] / b[i][j];
        }
    }

    // Matrix determinant
    int det = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            det += a[i][j] * b[i][j];
        }
    }
    det = det * (M * N);

    // Print the results
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("Determinant: %d\n", det);

    return 0;
}