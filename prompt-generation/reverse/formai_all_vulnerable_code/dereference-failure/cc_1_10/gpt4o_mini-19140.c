//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 1000 // Sample rate in Hz
#define FREQUENCY 5      // Frequency of the sine wave
#define DURATION 2       // Duration in seconds
#define ORDER 2          // Order of the Butterworth filter

// Butterworth filter coefficients
double a[ORDER + 1], b[ORDER + 1];

// Function to calculate Butterworth filter coefficients
void calc_butterworth(double cutoff) {
    double q = 1.0 / sqrt(2);
    double k = tan(M_PI * cutoff / SAMPLE_RATE);
    double norm = 1.0 / (1 + k / q + k * k);
    
    b[0] = k * k * norm;
    b[1] = 2 * b[0];
    b[2] = b[0];
    a[1] = 2 * (k * k - 1) * norm;
    a[2] = (1 - k / q + k * k) * norm;
}

// Function to apply the filter on a signal
void apply_filter(double *input, double *output, int length) {
    for (int n = 0; n < length; n++) {
        output[n] = b[0] * input[n];
        if (n > 0) {
            output[n] += b[1] * input[n - 1];
        }
        if (n > 1) {
            output[n] += b[2] * input[n - 2];
        }
        if (n > 0) {
            output[n] -= a[1] * output[n - 1];
        }
        if (n > 1) {
            output[n] -= a[2] * output[n - 2];
        }
    }
}

// Main function
int main() {
    int num_samples = SAMPLE_RATE * DURATION;
    double *input_signal = malloc(num_samples * sizeof(double));
    double *filtered_signal = malloc(num_samples * sizeof(double));
    
    // Generate input sine wave
    for (int i = 0; i < num_samples; i++) {
        input_signal[i] = sin(2 * M_PI * FREQUENCY * (i / (double) SAMPLE_RATE));
    }
    
    // Design Butterworth filter
    double cutoff = 10; // Cutoff frequency in Hz
    calc_butterworth(cutoff);
    
    // Apply filter to the input signal
    apply_filter(input_signal, filtered_signal, num_samples);
    
    // Write the input and output to files for plotting
    FILE *input_file = fopen("input_signal.txt", "w");
    FILE *output_file = fopen("filtered_signal.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening files!\n");
        free(input_signal);
        free(filtered_signal);
        return 1;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(input_file, "%lf %lf\n", (double)i / SAMPLE_RATE, input_signal[i]);
        fprintf(output_file, "%lf %lf\n", (double)i / SAMPLE_RATE, filtered_signal[i]);
    }

    fclose(input_file);
    fclose(output_file);
    
    // Clean up
    free(input_signal);
    free(filtered_signal);
    
    // Plotting with GNUplot
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Sine Wave and Filtered Signal'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time (s)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Amplitude'\n");
        fprintf(gnuplotPipe, "plot 'input_signal.txt' with lines title 'Input Signal',\n");
        fprintf(gnuplotPipe, "     'filtered_signal.txt' with lines title 'Filtered Signal'\n");
        pclose(gnuplotPipe);
    } else {
        fprintf(stderr, "Could not open Gnuplot.\n");
        return 1;
    }

    return 0;
}