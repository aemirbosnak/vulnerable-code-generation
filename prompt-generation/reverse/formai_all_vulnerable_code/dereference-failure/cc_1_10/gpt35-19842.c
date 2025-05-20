//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    float real;
    float imag;
} Complex;

void dft(Complex x[], int N)
{
    Complex *X = (Complex*)malloc(N*sizeof(Complex));

    for (int k = 0; k < N; k++)
    {
        X[k].real = 0;
        X[k].imag = 0;

        for (int n = 0; n < N; n++)
        {
            float exp_factor = -2*PI*k*n/N;
            Complex exp_term;
            exp_term.real = cos(exp_factor);
            exp_term.imag = sin(exp_factor);
            Complex xn;
            xn.real = x[n].real;
            xn.imag = x[n].imag;
            Complex tmp = xn;

            tmp.real *= exp_term.real;
            tmp.imag *= exp_term.imag;

            X[k].real += tmp.real - tmp.imag;
            X[k].imag += tmp.real + tmp.imag;
        }
    }

    for (int k = 0; k < N; k++)
    {
        x[k].real = X[k].real;
        x[k].imag = X[k].imag;
    }

    free(X);
}

int main()
{
    Complex sample_data[8] = {
        {1.0f, -1.0f},
        {2.0f, 2.0f},
        {3.0f, 3.0f},
        {4.0f, 4.0f},
        {5.0f, 5.0f},
        {6.0f, 6.0f},
        {7.0f, 7.0f},
        {8.0f, 8.0f}
    };

    printf("Before DFT:\n");

    for (int i=0; i<8; i++)
    {
        printf("%0.1f + %0.1fi\n", sample_data[i].real, sample_data[i].imag);
    }

    dft(sample_data, 8);

    printf("\nAfter DFT:\n");

    for (int i=0; i<8; i++)
    {
        printf("%0.1f + %0.1fi\n", sample_data[i].real, sample_data[i].imag);
    }

    return 0;
}