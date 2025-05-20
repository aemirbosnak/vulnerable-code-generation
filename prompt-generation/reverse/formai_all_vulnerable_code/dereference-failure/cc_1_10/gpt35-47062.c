//FormAI DATASET v1.0 Category: Audio processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A function to add a gain to the input signal
void add_gain(float *input_signal, unsigned int num_samples, float gain) {
    unsigned int i;
    for(i=0; i<num_samples; i++) {
        input_signal[i] *= gain;
    }
}

// A function to filter the input signal using a high-pass filter
void high_pass_filter(float *input_signal, unsigned int num_samples, unsigned int sample_rate, float cutoff_freq) {
    // Calculate filter coefficients
    float c = tan(M_PI * cutoff_freq / sample_rate);
    float a1 = 1.0 / (1.0 + sqrt(2.0)*c + pow(c, 2));
    float a2 = 2 * a1;
    float a3 = a1;
    float b1 = 2.0 * a1 * (pow(c, 2) - 1.0);
    float b2 = a1 * (1.0 - sqrt(2.0)*c + pow(c, 2));
    
    // Create history
    float h1 = 0.0, h2 = 0.0;
    
    // Apply filter to signal
    unsigned int i;
    for(i=0; i<num_samples; i++) {
        float x = input_signal[i];
        float y = a1*x + a2*h1 + a3*h2 - b1*h1 - b2*h2;
        input_signal[i] = y;
        h2 = h1;
        h1 = y;
    }
}

int main() {
    // Generate a test signal
    const unsigned int SAMPLE_RATE = 44100;
    const unsigned int NUM_SAMPLES = 44100;
    float *signal = (float*)malloc(NUM_SAMPLES*sizeof(float));
    unsigned int i;
    for(i=0; i<NUM_SAMPLES; i++) {
        signal[i] = sin(2*M_PI*440*i/SAMPLE_RATE);
    }
    
    // Apply gain to signal
    float gain = 0.5;
    add_gain(signal, NUM_SAMPLES, gain);
    
    // Apply high-pass filter to signal
    float cutoff_freq = 1000.0;
    high_pass_filter(signal, NUM_SAMPLES, SAMPLE_RATE, cutoff_freq);
    
    // Print filtered signal to file
    FILE *output = fopen("output.txt", "w");
    for(i=0; i<NUM_SAMPLES; i++) {
        fprintf(output, "%f\n", signal[i]);
    }
    fclose(output);
    
    // Free memory
    free(signal);
    
    return 0;
}