//FormAI DATASET v1.0 Category: Digital signal processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int sample_rate = 44100; // sample frequency
    double cutoff_freq = 5000; // cutoff frequency
    double Q = 0.707; // Q-factor
    int n = 100000; // number of samples
    double dt = 1.0 / sample_rate; // time step
    double fc = 2 * PI * cutoff_freq; // angular cutoff frequency
    double alpha = sin(fc * dt / 2) / (2 * Q); // alpha value
    double b0 = (1 - cos(fc * dt)) / 2;
    double b1 = 1 - cos(fc * dt);
    double b2 = (1 - cos(fc * dt)) / 2;
    double a0 = 1 + alpha;
    double a1 = -2 * cos(fc * dt);
    double a2 = 1 - alpha;

    double *input = (double*) malloc(n * sizeof(double));
    double *output = (double*) malloc(n * sizeof(double));

    // generate test signal (5000 Hz sine wave + 1 kHz white noise)
    for (int i = 0; i < n; i++)
    {
        input[i] = sin(2 * PI * 5000 * i / sample_rate) + 0.1 * sin(2 * PI * 1000 * i / sample_rate);
    }

    // apply second-order low-pass filter using recursive difference equations
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int i = 0; i < n; i++)
    {
        double x0 = input[i];
        double y0 = (b0 / a0) * x0 + (b1 / a0) * x1 + (b2 / a0) * x2 - (a1 / a0) * y1 - (a2 / a0) * y2;
        output[i] = y0;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
    }

    // write output to file for further analysis
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%f\n", output[i]);
    }
    fclose(fp);

    // free memory
    free(input);
    free(output);

    return 0;
}