//FormAI DATASET v1.0 Category: Digital signal processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int num_samples = 1024; // number of samples to process
    double sampling_rate = 44100.0; // sampling rate in Hz

    // generate a test signal (sine wave with 440 Hz frequency)
    double amplitude = 0.5;
    double frequency = 440.0;
    double phase = 0.0;
    double time_step = 1.0 / sampling_rate;
    
    double *input_signal = (double *) malloc(sizeof(double) * num_samples);

    for (int i = 0; i < num_samples; i++) {
        double time = i * time_step;
        input_signal[i] = amplitude * sin(2 * PI * frequency * time + phase);
    }

    // perform a Discrete Fourier Transform (DFT) on the input signal
    double *reals = (double *) malloc(sizeof(double) * num_samples); // real parts
    double *imags = (double *) malloc(sizeof(double) * num_samples); // imaginary parts

    for (int k = 0; k < num_samples; k++) {
        reals[k] = 0;
        imags[k] = 0;
        for (int n = 0; n < num_samples; n++) {
            double angle = 2 * PI * k * n / num_samples;
            reals[k] += input_signal[n] * cos(angle);
            imags[k] -= input_signal[n] * sin(angle);
        }
    }

    // calculate the magnitude and phase of the DFT result
    double *magnitudes = (double *) malloc(sizeof(double) * num_samples);
    double *phases = (double *) malloc(sizeof(double) * num_samples);

    for (int k = 0; k < num_samples; k++) {
        magnitudes[k] = sqrt(reals[k] * reals[k] + imags[k] * imags[k]);
        phases[k] = atan2(imags[k], reals[k]);
    }

    // print the frequencies, magnitudes, and phases of the DFT result
    printf("Frequency (Hz)\tMagnitude\tPhase (radians)\n");
    for (int k = 0; k < num_samples / 2; k++) {
        double frequency = k * sampling_rate / num_samples;
        printf("%f\t%f\t%f\n", frequency, magnitudes[k], phases[k]);
    }

    // free allocated memory
    free(input_signal);
    free(reals);
    free(imags);
    free(magnitudes);
    free(phases);

    return 0;
}