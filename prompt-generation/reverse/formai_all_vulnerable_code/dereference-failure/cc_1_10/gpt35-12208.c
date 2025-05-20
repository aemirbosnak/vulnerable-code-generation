//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int num_samples = 1000;
    double amplitude = 1.0;
    double frequency = 10.0;
    double phase = 0.0;
    double sampling_rate = 100.0;
    
    double time_increment = 1.0 / sampling_rate;
    double time = 0.0;
    
    double *signal = (double*) malloc(num_samples * sizeof(double));
    
    int i;
    for(i = 0; i < num_samples; i++) {
        signal[i] = amplitude * sin(2.0 * PI * frequency * time + phase);
        time += time_increment;
    }
    
    // Apply a low-pass filter
    double cutoff_frequency = 5.0;
    double alpha = time_increment / (1.0 / (2.0 * PI * cutoff_frequency) + time_increment);
    double prev_output = 0.0;
    
    for(i = 0; i < num_samples; i++) {
        double input = signal[i];
        double output = alpha * input + (1.0 - alpha) * prev_output;
        prev_output = output;
        signal[i] = output;
    }
    
    // Calculate the power of the signal
    double power = 0.0;
    for(i = 0; i < num_samples; i++) {
        power += pow(signal[i], 2.0);
    }
    power /= num_samples;
    
    printf("Power of the signal: %f\n", power);
    
    free(signal);
    
    return 0;
}