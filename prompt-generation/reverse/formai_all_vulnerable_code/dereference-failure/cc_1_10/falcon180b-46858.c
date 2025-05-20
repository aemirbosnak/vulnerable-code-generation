//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int N, M;
    double* x, *h, *y;
    int i, j;

    // Input signal
    N = 100;
    x = (double*) malloc(N * sizeof(double));
    for (i = 0; i < N; i++) {
        x[i] = sin(2 * M_PI * i / 10);
    }

    // Filter coefficients
    M = 5;
    h = (double*) malloc(M * sizeof(double));
    for (i = 0; i < M; i++) {
        h[i] = (double) i / (double) M;
    }

    // Filter output
    y = (double*) malloc(N * sizeof(double));
    for (i = 0; i < N; i++) {
        y[i] = 0;
        for (j = 0; j < M; j++) {
            y[i] += h[j] * x[(i - j + N) % N];
        }
    }

    // Print results
    printf("Input signal:\n");
    for (i = 0; i < N; i++) {
        printf("%lf ", x[i]);
    }
    printf("\n");

    printf("Filter output:\n");
    for (i = 0; i < N; i++) {
        printf("%lf ", y[i]);
    }
    printf("\n");

    free(x);
    free(h);
    free(y);

    return 0;
}