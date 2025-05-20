//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double * hamming(double * inp, int length);
double * convolve(double * inp, double * filter, int inp_length, int filter_length);

int main()
{
    // Input signal
    double inp[8] = {2, 4, 1, 6, 3, 9, 7, 5};
    int inp_length = 8;

    // Hamming window
    double hamming_filter[8] = {0.08, 0.25319469, 0.6423596, 0.95105652,
                                0.95105652, 0.6423596, 0.25319469, 0.08};
    int filter_length = 8;

    // Apply Hamming window
    double * hamming_inp = hamming(inp, inp_length);

    // Convolve input signal with Hamming filter
    double * convolved = convolve(hamming_inp, hamming_filter, inp_length, filter_length);

    // Print convolved signal
    printf("Convolved Signal: ");
    for(int i = 0; i < inp_length; i++)
        printf("%.2f ", convolved[i]);
    printf("\n");

    return 0;
}

// Hamming window function
double * hamming(double * inp, int length)
{
    double * result = malloc(length * sizeof(double));

    for(int i = 0; i < length; i++)
        result[i] = inp[i] * (0.54 - 0.46 * cos((2 * PI * i) / (length - 1)));

    return result;
}

// Convolution function
double * convolve(double * inp, double * filter, int inp_length, int filter_length)
{
    int conv_length = inp_length + filter_length - 1;

    double * result = calloc(conv_length, sizeof(double));

    for(int i = 0; i < conv_length; i++)
        for(int j = 0; j < inp_length; j++)
            if((i - j) >= 0 && (i - j) < filter_length)
                result[i] += inp[j] * filter[i - j];

    return result;
}