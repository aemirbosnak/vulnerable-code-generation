//FormAI DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Module 1: Generate Sine wave signal */
void generate_sine_wave(float *output, int sample_rate, int freq, float amplitude, int duration) {
    int samples = sample_rate * duration;
    int i;
    for(i=0; i<samples; i++) {
        output[i] = amplitude * sin(2*M_PI*freq*i/sample_rate);
    }
}

/* Module 2: Apply low-pass filter to input signal */
void apply_lowpass_filter(float *input, float *output, int num_samples, int filter_cutoff) {
    int i;
    float alpha = 2*M_PI*filter_cutoff;
    float y = 0;
    for(i=0; i<num_samples; i++) {
        y = (1-alpha)*y + alpha*input[i];
        output[i] = y;
    }
}

/* Module 3: Calculate FFT of signal */
void calculate_fft(float *input, float *output, int num_samples) {
    int i, j, k;
    float real, imag;
    
    for(i=0; i<num_samples; i++) {
        real = imag = 0;
        for(j=0; j<num_samples; j++) {
            k = i*j % num_samples;
            real += input[j] * cos(2*M_PI*k/num_samples);
            imag += input[j] * sin(2*M_PI*k/num_samples);
        }
        output[i] = sqrt(real*real + imag*imag);
    }
}

int main()
{
    /* Define input parameters */
    int sample_rate = 44100; // Sample rate in Hz
    int freq = 1000; // Frequency in Hz
    float amplitude = 1; // Amplitude of sine wave
    int duration = 1; // Duration of signal in seconds
    int filter_cutoff = 500; // Cutoff frequency of low-pass filter
    
    /* Allocate memory for input and output signals */
    int num_samples = sample_rate * duration;
    float *input_signal = (float *) malloc(num_samples * sizeof(float));
    float *filtered_signal = (float *) malloc(num_samples * sizeof(float));
    float *fft_signal = (float *) malloc(num_samples * sizeof(float));
    
    /* Generate input signal */
    generate_sine_wave(input_signal, sample_rate, freq, amplitude, duration);
    
    /* Apply low-pass filter */
    apply_lowpass_filter(input_signal, filtered_signal, num_samples, filter_cutoff);
    
    /* Calculate FFT */
    calculate_fft(filtered_signal, fft_signal, num_samples);
    
    /* Print results */
    printf("Input signal: \n");
    int i;
    for(i=0; i<num_samples; i++) {
        printf("%f ", input_signal[i]);
    }
    printf("\n");
    
    printf("Filtered signal: \n");
    for(i=0; i<num_samples; i++) {
        printf("%f ", filtered_signal[i]);
    }
    printf("\n");
    
    printf("FFT of filtered signal: \n");
    for(i=0; i<num_samples; i++) {
        printf("%f ", fft_signal[i]);
    }
    printf("\n");
    
    /* Free memory */
    free(input_signal);
    free(filtered_signal);
    free(fft_signal);
    
    return 0;
}