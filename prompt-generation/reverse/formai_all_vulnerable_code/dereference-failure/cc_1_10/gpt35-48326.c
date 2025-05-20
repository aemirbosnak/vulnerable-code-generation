//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void complex_fft(double* real, double* imag, int n, int inverse);
int power_of_two(double n);

// Complex Fast Fourier Transform
void complex_fft(double* real, double* imag, int n, int inverse)
{
    int limit = 1;
    int bit_cnt = 0;
    while (limit < n)
    {
        limit <<= 1;
        bit_cnt++;
    }

    int *reversed = (int *)malloc(sizeof(int) * limit);
    reversed[0] = 0;

    for (int i = 1; i < limit; i++)
    {
        int j = reversed[i - 1];
        int k = bit_cnt - 1;

        while (k >= 0)
        {
            if ((j >> k) & 1)
                j ^= 1 << k;
            else
                break;
            k--;
        }

        reversed[i] = reversed[j] | 1 << (bit_cnt - 1 - k);
    }

    double *cos_table = (double *)malloc(sizeof(double) * n / 2);
    double *sin_table = (double *)malloc(sizeof(double) * n / 2);

    for (int i = 0; i < n / 2; i++)
    {
        cos_table[i] = cos(2 * PI * i / n);
        sin_table[i] = sin(2 * PI * i / n);
    }

    for (int i = 0; i < n; i++)
    {
        if (i < reversed[i])
        {
            double temp = real[i];
            real[i] = real[reversed[i]];
            real[reversed[i]] = temp;

            temp = imag[i];
            imag[i] = imag[reversed[i]];
            imag[reversed[i]] = temp;
        }
    }

    for (int size = 2; size <= n; size <<= 1)
    {
        int halfsize = size / 2;
        int tablestep = n / size;

        for (int i = 0; i < n; i += size)
        {
            for (int j = i, k = 0; j < i + halfsize; j++, k += tablestep)
            {
                int l = j + halfsize;

                double re = real[l] * cos_table[k] + imag[l] * sin_table[k];
                double im = -real[l] * sin_table[k] + imag[l] * cos_table[k];

                real[l] = real[j] - re;
                imag[l] = imag[j] - im;

                real[j] += re;
                imag[j] += im;
            }
        }
    }

    if (inverse)
    {
        for (int i = 0; i < n; i++)
        {
            real[i] /= n;
            imag[i] /= n;
        }
    }
}

// Test code
int main() {
    int size = 8;
    int is_inverse = 0;
    double real[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    double imag[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    printf("Input (real):\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", real[i]);
    }

    printf("\n");

    printf("Input (imaginary):\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", imag[i]);
    }

    printf("\n");

    complex_fft(real, imag, size, is_inverse);

    printf("Output (real):\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", real[i]);
    }

    printf("\n");

    printf("Output (imaginary):\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", imag[i]);
    }

    return 0;
}