//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 1000
#define DURATION 1.0
#define PI 3.14159265358979323846
#define NOISE_LEVEL 0.5
#define ALPHA 0.1 // Low-pass filter coefficient

// Function prototypes
void generate_signal(double *signal, int samples);
void add_noise(double *signal, int samples);
void low_pass_filter(const double *input, double *output, int samples);
void plot_signals(const char *filename);

int main() {
    int samples = (int)(SAMPLE_RATE * DURATION);
    double *signal = malloc(samples * sizeof(double));
    double *noisy_signal = malloc(samples * sizeof(double));
    double *filtered_signal = malloc(samples * sizeof(double));
    
    // Generate clean sine wave signal
    generate_signal(signal, samples);
    
    // Add noise to the signal
    add_noise(signal, samples);
    
    // Apply low-pass filter
    low_pass_filter(noisy_signal, filtered_signal, samples);
    
    // Write to file for plotting
    FILE *fp = fopen("signals.dat", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error creating file.\n");
        return 1;
    }
    
    for (int i = 0; i < samples; i++) {
        fprintf(fp, "%d\t%f\t%f\t%f\n", 
                i, signal[i], noisy_signal[i], filtered_signal[i]);
    }
    
    fclose(fp);
    
    // Plot the signals
    plot_signals("signals.dat");
    
    // Free allocated memory
    free(signal);
    free(noisy_signal);
    free(filtered_signal);
    
    return 0;
}

// Function to generate a clean sine wave
void generate_signal(double *signal, int samples) {
    double frequency = 5.0; // Frequency of the sine wave
    for (int i = 0; i < samples; i++) {
        signal[i] = sin(2 * PI * frequency * ((double)i / SAMPLE_RATE));
    }
}

// Function to add noise to the signal
void add_noise(double *signal, int samples) {
    srand(time(NULL));
    
    for (int i = 0; i < samples; i++) {
        double noise = ((double)rand() / RAND_MAX) * 2 * NOISE_LEVEL - NOISE_LEVEL; // Uniform noise
        signal[i] += noise;
    }
}

// Function to apply a low-pass filter
void low_pass_filter(const double *input, double *output, int samples) {
    output[0] = input[0]; // Initialize the first value
    
    for (int i = 1; i < samples; i++) {
        output[i] = ALPHA * input[i] + (1 - ALPHA) * output[i-1];
    }
}

// Function to plot the signals using GNUplot
void plot_signals(const char *filename) {
    FILE *gnuplot = popen("gnuplot -persistent", "w");
    if (gnuplot == NULL) {
        fprintf(stderr, "Error opening pipe to GNUplot.\n");
        return;
    }
    
    fprintf(gnuplot, "set title 'Signal Processing'\n");
    fprintf(gnuplot, "set xlabel 'Sample'\n");
    fprintf(gnuplot, "set ylabel 'Amplitude'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "plot '%s' using 1:2 with lines title 'Original Signal', \
                      '%s' using 1:3 with lines title 'Noisy Signal', \
                      '%s' using 1:4 with lines title 'Filtered Signal'\n", 
                      filename, filename, filename);
    
    fflush(gnuplot); // Ensure commands are sent to GNUplot
    pclose(gnuplot);
}