//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables
    int N, M;
    double *x, *y, *z, *w;
    double pi = 3.14159265358979323846;
    int i, j;

    // Get user input for signal length
    printf("Enter signal length: ");
    scanf("%d", &N);

    // Allocate memory for signals
    x = (double *) malloc(N * sizeof(double));
    y = (double *) malloc(N * sizeof(double));
    z = (double *) malloc(N * sizeof(double));
    w = (double *) malloc(N * sizeof(double));

    // Initialize signals with random noise
    for (i = 0; i < N; i++) {
        x[i] = rand() / RAND_MAX;
        y[i] = rand() / RAND_MAX;
    }

    // Compute Fourier Transform of signals
    for (i = 0; i < N; i++) {
        w[i] = 2 * pi * i / N;
        z[i] = 0;
        for (j = 0; j < N; j++) {
            z[i] += x[j] * cos(w[i] * j) + y[j] * sin(w[i] * j);
        }
    }

    // Print Fourier Transform
    printf("Fourier Transform:\n");
    for (i = 0; i < N; i++) {
        printf("%lf\t", z[i]);
    }
    printf("\n");

    // Deallocate memory
    free(x);
    free(y);
    free(z);
    free(w);

    return 0;
}