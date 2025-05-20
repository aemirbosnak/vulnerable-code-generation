//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100 // Sample rate in Hz
#define DURATION 5        // Duration of the signal in seconds
#define PI 3.14159265

// Function to generate a sine wave signal
void generate_sine_wave(double frequency, double *buffer, size_t samples) {
    for (size_t i = 0; i < samples; i++) {
        buffer[i] = sin(2 * PI * frequency * (i / (double)SAMPLE_RATE));
    }
}

// Function to add white noise to a signal
void add_white_noise(double *signal, double *noise, size_t samples, double noise_amplitude) {
    for (size_t i = 0; i < samples; i++) {
        double random_value = (rand() / (double)RAND_MAX) * 2 - 1; // Generate a random value in range [-1, 1]
        noise[i] = random_value * noise_amplitude; // Scale by desired noise amplitude
        signal[i] += noise[i]; // Add noise to signal
    }
}

// Function to compute the mean of a signal
double compute_mean(double *signal, size_t samples) {
    double sum = 0.0;
    for (size_t i = 0; i < samples; i++) {
        sum += signal[i];
    }
    return sum / samples;
}

// Function to compute the standard deviation of a signal
double compute_stddev(double *signal, size_t samples, double mean) {
    double sum = 0.0;
    for (size_t i = 0; i < samples; i++) {
        sum += (signal[i] - mean) * (signal[i] - mean);
    }
    return sqrt(sum / samples);
}

// Function to save signal to a text file
void save_signal_to_file(const char *filename, double *signal, size_t samples) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (size_t i = 0; i < samples; i++) {
        fprintf(file, "%lf\n", signal[i]);
    }
    fclose(file);
}

// Main function to demonstrate DSP pipeline
int main() {
    size_t total_samples = SAMPLE_RATE * DURATION;
    double *sine_wave = (double *)malloc(total_samples * sizeof(double));
    double *noise = (double *)malloc(total_samples * sizeof(double));
    
    // Seed the random number generator
    srand(time(NULL));
    
    double frequency = 440.0; // Frequency of the sine wave (A4)
    double noise_amplitude = 0.1; // Amplitude of the noise

    // Generate sine wave
    generate_sine_wave(frequency, sine_wave, total_samples);
    
    // Add white noise
    add_white_noise(sine_wave, noise, total_samples, noise_amplitude);

    // Compute statistical properties
    double mean = compute_mean(sine_wave, total_samples);
    double stddev = compute_stddev(sine_wave, total_samples, mean);
    
    // Print statistical properties
    printf("Signal Statistics:\n");
    printf("Mean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", stddev);
    
    // Save the noisy signal to a file
    save_signal_to_file("noisy_signal.txt", sine_wave, total_samples);
    
    // Free allocated memory
    free(sine_wave);
    free(noise);

    return 0;
}