//FormAI DATASET v1.0 Category: Digital signal processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program will create a digital signal processing algorithm that will
 * apply an arbitrary function to an input signal. The function accepts a floating
 * point signal array and a size parameter. The output added its samples and scale it by
 * dividing it by the size of the input array. The scale could be any numeric value.*/

float* arbitrary_function(float signal[], int size)
{
    // Allocate memory for output signal
    float* output_signal = (float*) malloc(size * sizeof(float));
    float scale = 2.0;

    // Apply arbitrary function to each sample of input signal
    for (int i = 0; i < size; i++) {
        output_signal[i] = powf(signal[i], 2);
    }

    // Add all samples of output signal
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += output_signal[i];
    }

    // Scale output signal by dividing it by size of input array and multiplying by scale
    float scalar = scale / size;
    for (int i = 0; i < size; i++) {
        output_signal[i] = scalar * output_signal[i];
    }

    // Return final output signal
    return output_signal;
}

int main()
{
    // Define input signal and its size
    float signal[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(signal) / sizeof(float);

    // Call arbitrary_function and retrieve output signal
    float* output_signal = arbitrary_function(signal, size);

    // Display final output signal
    printf("Final output signal: \n");
    for (int i = 0; i < size; i++) {
        printf("Sample %d: %f\n", i, output_signal[i]);
    }

    // Free memory allocated for output signal
    free(output_signal);

    return 0;
}