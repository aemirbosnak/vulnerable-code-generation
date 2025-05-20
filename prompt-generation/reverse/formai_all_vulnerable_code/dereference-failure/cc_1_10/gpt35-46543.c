//FormAI DATASET v1.0 Category: Digital signal processing ; Style: accurate
/* This C program demonstrates an example of digital signal processing using discrete Fourier transform. Simply put, it takes an input signal and transforms it into a frequency-domain representation. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

/* Define complex numbers for complex arithmetic */
typedef struct {
    double real;
    double imag;
} complex;

/* Discrete Fourier transform */
void DFT(complex *x, int N) {
    int k, n;
    complex *X;
    X = (complex *)malloc(sizeof(complex)*N);

    for (k = 0; k < N; k++) {
        X[k].real = 0.0;
        X[k].imag = 0.0;
        for (n = 0; n < N; n++) {
            X[k].real += x[n].real * cos(2 * PI * k * n / N) + x[n].imag * sin(2 * PI * k * n / N);
            X[k].imag += x[n].imag * cos(2 * PI * k * n / N) - x[n].real * sin(2 * PI * k * n / N);
        }
    }

    /* Print the frequency-domain representation */
    printf("Frequency-domain representation:\n");
    for (k = 0; k < N; k++) {
        printf("X[%d] = %f + %fi\n", k, X[k].real, X[k].imag);
    }

    /* Free the dynamically allocated memory */
    free(X);
}

/* Main function */
int main() {
    int N, n;
    complex *x;

    /* Take input of number of samples */
    printf("Enter the number of samples: ");
    scanf("%d", &N);

    /* Allocate memory for the samples */
    x = (complex *)malloc(sizeof(complex)*N);

    /* Input the samples */
    printf("Enter the samples:\n");
    for (n = 0; n < N; n++) {
        printf("x[%d] = ", n);
        scanf("%lf", &x[n].real);
        x[n].imag = 0.0;
    }

    DFT(x, N);
    free(x);

    return 0;
}