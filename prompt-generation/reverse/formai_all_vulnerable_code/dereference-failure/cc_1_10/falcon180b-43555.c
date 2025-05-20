//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void FFT(double *x, int n, int isign) {
    int i, j, k, l, m, mmax, istep;
    double wtemp, wr, wpr, wpi, theta;
    double *v, *u, *a, *b;

    theta = PI / n;
    mmax = 1;
    while (mmax < n) {
        mmax <<= 1;
    }
    istep = 1;
    while (istep < mmax) {
        istep <<= 1;
    }

    v = (double *)malloc(sizeof(double) * mmax);
    u = (double *)malloc(sizeof(double) * mmax);
    a = (double *)malloc(sizeof(double) * mmax);
    b = (double *)malloc(sizeof(double) * mmax);

    for (i = 0; i < n; i++) {
        v[i] = x[i];
    }

    for (k = 1; k < mmax; k <<= 1) {
        for (j = 0; j < mmax; j += k << 1) {
            for (l = 0; l < k; l++) {
                m = j + l;
                u[m] = v[m] + v[m + k];
                v[m] -= v[m + k];
            }
            for (l = 0; l < k; l++) {
                m = j + l;
                v[m] = v[m] + u[m + k];
                u[m] -= u[m + k];
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = v[i];
    }

    free(v);
    free(u);
    free(a);
    free(b);
}

int main() {
    int n;
    double *x, *y;
    printf("Enter the number of samples: ");
    scanf("%d", &n);

    x = (double *)malloc(sizeof(double) * n);
    y = (double *)malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++) {
        printf("Enter sample %d: ", i);
        scanf("%lf", &x[i]);
    }

    FFT(x, n, -1);

    for (int i = 0; i < n; i++) {
        printf("Sample %d: %lf\n", i, x[i]);
    }

    return 0;
}