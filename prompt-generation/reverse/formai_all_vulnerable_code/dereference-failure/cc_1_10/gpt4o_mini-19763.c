//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h> // For sleep function

#define SAMPLE_RATE 44100 // 44.1 kHz sample rate
#define DURATION 2        // 2 seconds duration
#define FREQ 440         // A4 note frequency (440 Hz)
#define FILTER_ALPHA 0.1  // Alpha for low-pass filter

void generate_sine_wave(float *signal, int size, float frequency) {
    for (int i = 0; i < size; ++i) {
        signal[i] = sin(2 * M_PI * frequency * (i / (float)SAMPLE_RATE)); // Fill array with sine values
    }
}

void apply_low_pass_filter(float *input, float *output, int size) {
    output[0] = input[0]; // Initialize the first output
    for (int i = 1; i < size; ++i) {
        output[i] = (FILTER_ALPHA * input[i]) + ((1 - FILTER_ALPHA) * output[i - 1]); // Simple filter
    }
}

void print_signal(float *signal, int size) {
    for (int i = 0; i < size; i += SAMPLE_RATE / 10) { // Print every 10th sample
        int num_hashes = (int)(signal[i] * 10); // Scale for display
        num_hashes = num_hashes < 0 ? -num_hashes : num_hashes; // Handle negative values
        printf("%c", signal[i] >= 0 ? ' ' : '-'); // Print sign indicator
        for (int j = 0; j < num_hashes; j++) {
            printf("#"); // Print hashes to represent amplitude
        }
        printf("\n");
    }
}

int main() {
    int num_samples = SAMPLE_RATE * DURATION; // Total number of samples
    float *sine_wave = (float *)malloc(num_samples * sizeof(float));
    float *filtered_signal = (float *)malloc(num_samples * sizeof(float));

    // Generate a happy sine wave signal
    generate_sine_wave(sine_wave, num_samples, FREQ);

    // Apply the low-pass filter
    apply_low_pass_filter(sine_wave, filtered_signal, num_samples);

    // Print original and filtered signals
    printf("Original Sine Wave Signal:\n");
    print_signal(sine_wave, num_samples);
    sleep(1); // Pause to create a separation
    
    printf("\nFiltered Signal:\n");
    print_signal(filtered_signal, num_samples);

    // Free allocated memory
    free(sine_wave);
    free(filtered_signal);

    return 0;
}