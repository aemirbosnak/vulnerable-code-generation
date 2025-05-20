//FormAI DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to apply bit reversal to the given index
int bitReversal(int index, int NumBits)
{
    int reversedIndex = 0;
    for (int i = 0; i < NumBits; i++)
    {
        reversedIndex <<= 1;
        reversedIndex |= index & 1;
        index >>= 1;
    }
    return reversedIndex;
} 

// Function to perform Fast Fourier Transform
void fft(float *x, float *y, int NumSamples)
{
    int NumBits = log2(NumSamples);
    for (int i = 0; i < NumSamples; i++)
    {
        int j = bitReversal(i, NumBits);
        if (j > i)
        {
            // swap x[i] with x[j]
            float temp = x[i];
            x[i] = x[j];
            x[j] = temp;
            // swap y[i] with y[j]
            temp = y[i];
            y[i] = y[j];
            y[j] = temp;
        }
    }
    for (int k = 2; k <= NumSamples; k *= 2)
    {
        float imaginaryTerm = -1.0;
        float imaginaryFactor = 0.0;
        for (int l = 0; l < k/2; l++)
        {
            float realFactor = cos(M_PI*l/(k/2));
            imaginaryFactor = imaginaryTerm*sin(M_PI*l/(k/2));
            for (int m = l; m < NumSamples; m += k)
            {
                int n = m + k/2;
                float temp1 = realFactor*x[n] - imaginaryFactor*y[n];
                float temp2 = realFactor*y[n] + imaginaryFactor*x[n];
                x[n] = x[m] - temp1;
                y[n] = y[m] - temp2;
                x[m] += temp1;
                y[m] += temp2;
            }
        }
    }
}

int main()
{
    // Input signal with 16 samples
    float x[] = {1.0, 0.5, 1.5, 1.0, -1.0, -0.5, -1.5, -1.0, 1.0, 0.5, 1.5, 1.0, -1.0, -0.5, -1.5, -1.0};
    float y[] = {0.0};
    int NumSamples = sizeof(x)/sizeof(float);

    // Perform FFT
    fft(x, y, NumSamples);

    // Print output
    printf("FFT Output:\n");
    for (int i = 0; i < NumSamples; i++)
    {
        printf("%d. %f + i%f\n", i, x[i], y[i]);
    }

    return 0;
}