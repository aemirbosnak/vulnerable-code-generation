//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <math.h>
#define PI M_PI

#define N 32
#define Fs 1000.0
#define fs 1000.0
#define T 1.0
#define f1 10.0
#define f2 5.0

double hamming(int n) {
    double h[N];
    double a = 0.54;
    double b = 0.46;

    for (int i = 0; i < N; i++) {
        h[i] = a - b * cos(2 * PI * i / N);
    }

    return h[n];
}

int main() {
    double *x, *y, *z, *w, sum_squares = 0.0, result = 0.0;
    int i;

    x = (double *)calloc(N, sizeof(double));
    y = (double *)calloc(N, sizeof(double));
    z = (double *)calloc(N, sizeof(double));
    w = (double *)calloc(N, sizeof(double));

    for (i = 0; i < N; i++) {
        x[i] = sin(2 * PI * f1 * T * i / fs);
        w[i] = hamming(i);
        y[i] = x[i] * w[i];
    }

    for (i = 0; i < N; i++) {
        z[i] = sin(2 * PI * f2 * T * i / fs) * 0.5;
        z[i] = fabs(y[i] * z[i]);
        sum_squares += pow(z[i], 2);
    }

    result = (sum_squares / N) * 100;

    printf("Result: %f %%\n", result);

    free(x);
    free(y);
    free(z);
    free(w);

    return 0;
}