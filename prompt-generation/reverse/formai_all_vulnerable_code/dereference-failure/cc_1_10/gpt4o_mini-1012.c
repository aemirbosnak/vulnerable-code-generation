//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define SAMPLE_RATE 1024
#define DURATION 1.0
#define FREQUENCY 5.0 // Frequency of sine wave

// Function to generate a sine wave
void generate_sine_wave(double *signal, int num_samples, double frequency, double sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * M_PI * frequency * (i / sample_rate));
    }
}

// Function to compute the FFT
void compute_fft(double *signal, fftw_complex *out, int num_samples) {
    fftw_plan plan;
    plan = fftw_plan_dft_r2c_1d(num_samples, signal, out, FFTW_ESTIMATE);
    
    // Execute the plan
    fftw_execute(plan);
    
    // Clean up
    fftw_destroy_plan(plan);
}

// Function to write data to a file for gnuplot
void write_data_to_file(fftw_complex *out, int num_samples, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < num_samples; i++) {
        double frequency = (double)i * SAMPLE_RATE / num_samples;
        double magnitude = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
        fprintf(fp, "%f %f\n", frequency, magnitude);
    }

    fclose(fp);
}

// Function to plot the results using gnuplot
void plot_results(const char *filename) {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    
    fprintf(gnuplotPipe, "set title 'Frequency Spectrum'\n");
    fprintf(gnuplotPipe, "set xlabel 'Frequency (Hz)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Magnitude'\n");
    fprintf(gnuplotPipe, "plot '%s' with lines\n", filename);
    
    fflush(gnuplotPipe);
    pclose(gnuplotPipe);
}

int main() {
    int num_samples = (int)(SAMPLE_RATE * DURATION);
    double *signal = (double *)malloc(num_samples * sizeof(double));
    fftw_complex *out = (fftw_complex *)malloc((num_samples / 2 + 1) * sizeof(fftw_complex));

    // Generate the sine wave
    generate_sine_wave(signal, num_samples, FREQUENCY, SAMPLE_RATE);
    
    // Compute FFT
    compute_fft(signal, out, num_samples);
    
    // Write the output to a file
    const char *output_filename = "fft_output.dat";
    write_data_to_file(out, num_samples / 2 + 1, output_filename);
    
    // Plotting the results
    plot_results(output_filename);
    
    // Clean up
    free(signal);
    free(out);
    
    return 0;
}