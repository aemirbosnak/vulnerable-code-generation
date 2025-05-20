//FormAI DATASET v1.0 Category: Digital signal processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A function to generate an irregular sinusoidal signal
float generateSignal(float time) {
    return sin(5*time) + pow(sin(3*time), 2) + cos(time/2);
}

int main() {
    float sample_rate = 100.0; // Sampling rate in Hz
    float duration = 5.0; // Total duration of signal in seconds
    float time_step = 1/sample_rate; // Time step in seconds
    int num_samples = duration*sample_rate; // Number of samples to take

    float *signal = (float*) malloc(num_samples * sizeof(float)); // Dynamic allocation of signal array

    for (int i=0; i<num_samples; i++) {
        float time = i*time_step;
        signal[i] = generateSignal(time);
    }

    // A low-pass filter implementation to smooth out the signal
    float prev_output = signal[0]; // Initialize output to first sample
    float alpha = 0.1; // Filter coefficient
    for (int i=1; i<num_samples; i++) {
        float output = alpha*signal[i] + (1-alpha)*prev_output;
        prev_output = output;
        signal[i] = output;
    }

    // Normalize the signal
    float max_value = 0.0;
    for (int i=0; i<num_samples; i++) {
        if (fabs(signal[i]) > max_value) {
            max_value = fabs(signal[i]);
        }
    }
    for (int i=0; i<num_samples; i++) {
        signal[i] /= max_value;
    }

    // Print out the signal for visualization purposes
    for (int i=0; i<num_samples; i++) {
        printf("%f, ", signal[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }

    free(signal); // Free up dynamic memory

    return 0;
}