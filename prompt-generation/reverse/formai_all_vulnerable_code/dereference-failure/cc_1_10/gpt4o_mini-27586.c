//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 2
#define PI 3.14159265
#define SIGNAL_FREQ 440    // Frequency of the sine wave (A4 note)
#define CUTOFF_FREQ 2000   // Cutoff frequency for the low-pass filter

// Structure to store filter coefficients
typedef struct {
    double a[3]; // Feedback coefficients (higher indices correspond to lower orders)
    double b[3]; // Feedforward coefficients
    double x[2]; // Input values
    double y[2]; // Output values
} ButterworthFilter;

// Function to initialize the Butterworth filter
void init_filter(ButterworthFilter* filter) {
    double omega = 2 * PI * CUTOFF_FREQ / SAMPLE_RATE;
    double alpha = sin(omega) / (2 * 0.707); // 0.707 is a damping factor
    double cos_omega = cos(omega);

    filter->b[0] = (1 - cos_omega) / 2;
    filter->b[1] = 1 - cos_omega;
    filter->b[2] = filter->b[0];
    filter->a[0] = 1 + alpha;
    filter->a[1] = -2 * cos_omega;
    filter->a[2] = 1 - alpha;

    // Normalize coefficients
    for (int i = 0; i < 3; i++) {
        filter->b[i] /= filter->a[0];
        filter->a[i] /= filter->a[0];
    }

    filter->x[0] = filter->x[1] = 0.0;
    filter->y[0] = filter->y[1] = 0.0;
}

// Function to process input samples using the low-pass filter
double process_filter(ButterworthFilter* filter, double input) {
    // Shift previous samples
    filter->x[0] = filter->x[1];
    filter->x[1] = input;

    // Calculate output sample
    filter->y[0] = filter->y[1];
    filter->y[1] = filter->b[0] * filter->x[1] + filter->b[1] * filter->x[0] + filter->a[1] * filter->y[0];

    return filter->y[1];
}

// Function to generate a sine wave signal
void generate_sine_wave(double* buffer, int samples, double frequency) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = sin(2 * PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

// Function to save the processed samples to a file
void save_to_file(const char* filename, double* buffer, int samples) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        exit(1);
    }
    for (int i = 0; i < samples; i++) {
        fprintf(file, "%lf\n", buffer[i]);
    }
    fclose(file);
}

// Main function demonstrating DSP with a low-pass filter
int main() {
    int num_samples = SAMPLE_RATE * DURATION;
    double* signal = (double*)malloc(num_samples * sizeof(double));
    double* filtered_signal = (double*)malloc(num_samples * sizeof(double));
    
    if (!signal || !filtered_signal) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    // Generate a sine wave signal
    generate_sine_wave(signal, num_samples, SIGNAL_FREQ);
    
    // Initialize the Butterworth filter
    ButterworthFilter filter;
    init_filter(&filter);
    
    // Process each sample through the filter
    for (int i = 0; i < num_samples; i++) {
        filtered_signal[i] = process_filter(&filter, signal[i]);
    }
    
    // Save the results to files
    save_to_file("original_signal.txt", signal, num_samples);
    save_to_file("filtered_signal.txt", filtered_signal, num_samples);
    
    // Clean up
    free(signal);
    free(filtered_signal);
    
    printf("Processing complete! Check 'original_signal.txt' and 'filtered_signal.txt' for results.\n");
    return 0;
}