//FormAI DATASET v1.0 Category: Digital signal processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void DFT(double *input, double *real_output, double *imag_output, int N) {
    int k, n;
    double arg;
    double *cosine, *sine, *temp_real, *temp_imag;

    cosine = (double *) malloc(sizeof(double) * N/2);
    sine = (double *) malloc(sizeof(double) * N/2);
    temp_real = (double *) malloc(sizeof(double) * N);
    temp_imag = (double *) malloc(sizeof(double) * N);
    
    for (k = 0; k < N/2; k++) {
        arg = -2 * PI * k / N;
        cosine[k] = cos(arg);
        sine[k] = sin(arg);
    }

    for (n = 0; n < N; n++) {
        temp_real[n] = 0;
        temp_imag[n] = 0;
        for (k = 0; k < N/2; k++) {
            temp_real[n] += input[2*k] * cosine[k] + input[2*k+1] * sine[k];
            temp_imag[n] += -input[2*k] * sine[k] + input[2*k+1] * cosine[k];
        }
    }

    for (n = 0; n < N; n++) {
        real_output[n] = temp_real[n];
        imag_output[n] = temp_imag[n];
    }

    free(cosine);
    free(sine);
    free(temp_real);
    free(temp_imag);
}

int main() {
    double input[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double real_output[8], imag_output[8];
    int i;

    DFT(input, real_output, imag_output, 8);

    for (i = 0; i < 8; i++) {
        printf("DFT Bin %d: Real = %f, Imaginary = %f\n", i, real_output[i], imag_output[i]);
    }

    return 0;
}