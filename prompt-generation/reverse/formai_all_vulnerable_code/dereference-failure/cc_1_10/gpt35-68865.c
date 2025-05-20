//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program demonstrates digital signal processing by generating a sine wave
// of frequency 1000 Hz, sampling it at 8000 Hz, and applying a low-pass filter
// to remove higher frequencies.

int main() {
    // frequency of the sine wave
    int freq = 1000;
    
    // number of samples per second (sampling rate)
    int sample_rate = 8000;
    
    // duration of the signal in seconds
    int duration = 1;
    
    // amplitude of the sine wave
    int amplitude = 10000;
    
    // angular frequency of the sine wave
    double omega = 2 * M_PI * freq;
    
    // compute the number of samples in the signal
    int num_samples = duration * sample_rate;
    
    // allocate memory for the signal
    int *signal = (int *)malloc(sizeof(int) * num_samples);
    
    // generate the sine wave
    for (int i = 0; i < num_samples; i++) {
        signal[i] = amplitude * sin(omega * i / sample_rate);
    }
    
    // apply a low-pass filter
    double RC = 1.0 / (2 * M_PI * 1000);
    double dt = 1.0 / sample_rate;
    double alpha = dt / (RC + dt);
    int *filtered_signal = (int *)malloc(sizeof(int) * num_samples);
    filtered_signal[0] = signal[0];
    for (int i = 1; i < num_samples; i++) {
        filtered_signal[i] = alpha * signal[i] + (1 - alpha) * filtered_signal[i-1];
    }
    
    // write the signal to a file
    FILE *file = fopen("signal.txt", "w");
    for (int i = 0; i < num_samples; i++) {
        fprintf(file, "%d\n", filtered_signal[i]);
    }
    fclose(file);
    
    // free memory
    free(signal);
    free(filtered_signal);
    
    return 0;
}