//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the signal length
#define N 1024

// Generate a sine wave signal
double *generate_sine_wave(double frequency, double sampling_rate) {
    double *signal = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2 * M_PI * frequency * i / sampling_rate);
    }
    return signal;
}

// Apply a moving average filter to the signal
double *moving_average_filter(double *signal, int window_size) {
    double *filtered_signal = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < window_size; j++) {
            if (i - j >= 0) {
                sum += signal[i - j];
            }
        }
        filtered_signal[i] = sum / window_size;
    }
    return filtered_signal;
}

// Plot the signal and the filtered signal
void plot_signals(double *signal, double *filtered_signal) {
    // Create a gnuplot script
    FILE *gnuplot_script = fopen("signals.gp", "w");
    fprintf(gnuplot_script, "set terminal png\n");
    fprintf(gnuplot_script, "set output \"signals.png\"\n");
    fprintf(gnuplot_script, "plot \"-\" with lines title \"Original Signal\"\n");
    fprintf(gnuplot_script, "plot \"-\" with lines title \"Filtered Signal\"\n");
    
    // Write the signal data to the script
    for (int i = 0; i < N; i++) {
        fprintf(gnuplot_script, "%d %f\n", i, signal[i]);
    }
    fprintf(gnuplot_script, "e\n");
    
    // Write the filtered signal data to the script
    for (int i = 0; i < N; i++) {
        fprintf(gnuplot_script, "%d %f\n", i, filtered_signal[i]);
    }
    fclose(gnuplot_script);
    
    // Execute the gnuplot script
    system("gnuplot signals.gp");
}

int main() {
    // Generate a sine wave signal with a frequency of 100 Hz and a sampling rate of 1000 Hz
    double *signal = generate_sine_wave(100, 1000);
    
    // Apply a moving average filter to the signal with a window size of 50
    double *filtered_signal = moving_average_filter(signal, 50);
    
    // Plot the original signal and the filtered signal
    plot_signals(signal, filtered_signal);
    
    // Free the allocated memory
    free(signal);
    free(filtered_signal);
    
    return 0;
}