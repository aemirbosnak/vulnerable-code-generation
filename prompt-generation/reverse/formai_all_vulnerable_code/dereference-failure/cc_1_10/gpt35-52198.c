//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int N, i;
    float *x, *y, *twiddle_real, *twiddle_imag;

    printf("Enter the number of samples: ");
    scanf("%d", &N);

    x = (float *) malloc(N * sizeof(float));
    y = (float *) malloc(N * sizeof(float));
    twiddle_real = (float *) malloc(N/2 * sizeof(float));
    twiddle_imag = (float *) malloc(N/2 * sizeof(float));

    if (x == NULL || y == NULL || twiddle_real == NULL || twiddle_imag == NULL)
    {
        printf("Error: Insufficient Memory");
        return 1;
    }

    printf("Enter the samples:\n");

    for (i = 0; i < N; i++)
    {
        scanf("%f", &x[i]);
        y[i] = 0.0;
    }

    // Generate twiddle factors
    for (i = 0; i < N/2; i++)
    {
        twiddle_real[i] = cos(-2 * PI * i / N);
        twiddle_imag[i] = sin(-2 * PI * i / N);
    }

    // Perform FFT
    for (int k = 0; k < N; k++)
    {
        for (i = 0; i < N/2; i++)
        {
            y[k] += (x[2*i] * twiddle_real[i] - x[2*i+1] * twiddle_imag[i]) * exp(-2.0 * PI * i * k / N);
        }
    }

    printf("DFT output:\n");

    for (i = 0; i < N; i++)
    {
        printf("%f + j%f\n", y[i], 0.0);
    }

    free(x);
    free(y);
    free(twiddle_real);
    free(twiddle_imag);

    return 0;
}