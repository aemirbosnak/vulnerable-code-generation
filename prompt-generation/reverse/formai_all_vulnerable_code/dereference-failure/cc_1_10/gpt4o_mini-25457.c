//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sample rate and frequency for sine wave
#define SAMPLE_RATE 44100
#define FREQUENCY 440.0  // A4 note
#define DURATION 2.0  // Duration in seconds
#define PI 3.14159265358979323846

// Function to generate a sine wave of given frequency and duration
void generate_sine_wave(double frequency, double duration, double *buffer, int sample_rate) {
    int total_samples = (int)(duration * sample_rate);
    for (int i = 0; i < total_samples; i++) {
        buffer[i] = sin(2 * PI * frequency * (i / (double) sample_rate));
    }
}

// Function to apply a basic low-pass filter to the signal
void low_pass_filter(double *input, double *output, int num_samples, double cutoff_frequency, double sample_rate) {
    double RC = 1.0 / (2 * PI * cutoff_frequency);
    double dt = 1.0 / sample_rate;
    double alpha = dt / (RC + dt);
    
    output[0] = input[0];  // Initialize first sample
    for (int i = 1; i < num_samples; i++) {
        output[i] = output[i - 1] + alpha * (input[i] - output[i - 1]);
    }
}

// Function to save the wave data to a simple text file
void save_wave_data(const char *filename, double *buffer, int num_samples) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(file, "%lf\n", buffer[i]);
    }
    
    fclose(file);
}

// Function to display a snippet of the wave data
void print_wave_data(double *buffer, int num_samples) {
    printf("Wave Data Snippet:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%lf ", buffer[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

int main() {
    int num_samples = (int)(DURATION * SAMPLE_RATE);
    double *sine_wave = (double *)malloc(num_samples * sizeof(double));
    double *filtered_wave = (double *)malloc(num_samples * sizeof(double));

    // Generate a sine wave
    generate_sine_wave(FREQUENCY, DURATION, sine_wave, SAMPLE_RATE);
    printf("Sine Wave Generated: Frequency = %lf Hz, Duration = %lf seconds\n", FREQUENCY, DURATION);

    // Apply a low-pass filter to the sine wave
    low_pass_filter(sine_wave, filtered_wave, num_samples, 1000.0, SAMPLE_RATE);
    printf("Low-pass filter applied with cutoff frequency of 1000 Hz.\n");

    // Print a snippet of the filtered wave
    print_wave_data(filtered_wave, 20);

    // Save the filtered wave data to a file
    save_wave_data("filtered_wave.txt", filtered_wave, num_samples);
    printf("Filtered wave data saved to 'filtered_wave.txt'\n");

    // Cleanup
    free(sine_wave);
    free(filtered_wave);

    return 0;
}