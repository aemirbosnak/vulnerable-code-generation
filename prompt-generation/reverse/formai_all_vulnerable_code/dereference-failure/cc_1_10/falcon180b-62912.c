//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_multiply(int **a, int **b, int **c, int n);

int main() {
    int n = 1000;
    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(n * sizeof(int *));
    int **c = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    matrix_multiply(a, b, c, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU Time used: %lf seconds\n", cpu_time_used);

    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}

void matrix_multiply(int **a, int **b, int **c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}