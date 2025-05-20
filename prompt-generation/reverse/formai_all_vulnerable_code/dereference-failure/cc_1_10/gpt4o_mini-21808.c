//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0 // A4 note
#define DURATION 2.0 // in seconds
#define FILTER_SIZE 10 // Size of the moving average filter

// Function to generate a sine wave
void generate_sine_wave(float *buffer, int num_samples, float frequency, float sample_rate) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = sinf(2.0 * M_PI * frequency * ((float)i / sample_rate));
    }
}

// Function to apply a simple moving average filter
void apply_moving_average(float *input, float *output, int num_samples, int filter_size) {
    for (int i = 0; i < num_samples; i++) {
        float sum = 0.0;
        int count = 0;
        for (int j = -filter_size / 2; j <= filter_size / 2; j++) {
            if (i + j >= 0 && i + j < num_samples) {
                sum += input[i + j];
                count++;
            }
        }
        output[i] = sum / count;
    }
}

// Function to print the waveform to the console
void print_waveform(float *buffer, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        int num_chars = (int)((buffer[i] + 1.0) * 40); // Scale to the console
        for (int j = 0; j < num_chars; j++) {
            printf(" ");
        }
        printf("*\n"); // Print a star at the waveform position
    }
}

int main() {
    int num_samples = (int)(SAMPLE_RATE * DURATION);
    float *sine_wave = (float *)malloc(num_samples * sizeof(float));
    float *filtered_wave = (float *)malloc(num_samples * sizeof(float));

    // Generate the sine wave
    generate_sine_wave(sine_wave, num_samples, FREQUENCY, SAMPLE_RATE);

    // Apply the moving average filter
    apply_moving_average(sine_wave, filtered_wave, num_samples, FILTER_SIZE);

    // Print the original sine wave
    printf("Original Sine Wave:\n");
    print_waveform(sine_wave, num_samples);

    printf("\nFiltered Sine Wave:\n");
    print_waveform(filtered_wave, num_samples);

    // Free the allocated memory
    free(sine_wave);
    free(filtered_wave);

    return 0;
}