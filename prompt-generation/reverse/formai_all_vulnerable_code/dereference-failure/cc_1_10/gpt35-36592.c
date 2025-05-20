//FormAI DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LENGTH 1024    // Define the length of the signal
#define NUM_FILTER_TAPS 51    // Define the number of filter taps
#define PI 3.14159265358979323846

// Function to generate a test signal
void generate_signal(float *x)
{
    int i;
    
    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        x[i] = sin(2 * PI * i / SIGNAL_LENGTH);
    }
}

// Function to implement a low-pass FIR filter
void fir_filter(float *x, float *y, float *h)
{
    int i, j;
    
    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        y[i] = 0.0;
        
        for (j = 0; j < NUM_FILTER_TAPS; j++)
        {
            if (i - j >= 0)
            {
                y[i] += x[i - j] * h[j];
            }
        }
    }
}

int main()
{
    // Allocate memory for input, output and filter coefficients
    float *x = (float *)malloc(SIGNAL_LENGTH * sizeof(float));
    float *y = (float *)malloc(SIGNAL_LENGTH * sizeof(float));
    float *h = (float *)malloc(NUM_FILTER_TAPS * sizeof(float));
    
    // Generate test signal
    generate_signal(x);
    
    // Define filter coefficients for a low-pass FIR filter
    int i;
    for (i = 0; i < NUM_FILTER_TAPS; i++)
    {
        if (i == NUM_FILTER_TAPS / 2)
        {
            h[i] = 2.0 / NUM_FILTER_TAPS;
        }
        else
        {
            h[i] = sin(2 * PI * (i - NUM_FILTER_TAPS / 2) / NUM_FILTER_TAPS) / (PI * (i - NUM_FILTER_TAPS / 2));
        }
    }
    
    // Apply the FIR filter
    fir_filter(x, y, h);
    
    // Print the input and output signals
    printf("Input signal:\n");
    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        printf("%f\n", x[i]);
    }
    
    printf("Output signal:\n");
    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        printf("%f\n", y[i]);
    }
    
    // Free allocated memory
    free(x);
    free(y);
    free(h);
    
    return 0;
}