//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100  // Samples per second
#define DURATION 2          // Duration of the signal in seconds
#define FILTER_SIZE 20      // Size of the moving average filter

// Function declarations
void generate_signal(float *signal, int sample_count);
void apply_low_pass_filter(float *input, float *output, int sample_count, int filter_size);
void print_signal(float *signal, int sample_count);

int main() {
    int sample_count = SAMPLE_RATE * DURATION;
    
    // Allocate memory for the input and output signals
    float *signal = (float *)malloc(sample_count * sizeof(float));
    float *filtered_signal = (float *)malloc(sample_count * sizeof(float));

    if (signal == NULL || filtered_signal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate the original signal
    generate_signal(signal, sample_count);
    
    // Apply the low-pass filter
    apply_low_pass_filter(signal, filtered_signal, sample_count, FILTER_SIZE);
    
    // Print original and filtered signals
    printf("Original Signal:\n");
    print_signal(signal, sample_count);
    printf("\nFiltered Signal:\n");
    print_signal(filtered_signal, sample_count);

    // Free allocated memory
    free(signal);
    free(filtered_signal);

    return 0;
}

void generate_signal(float *signal, int sample_count) {
    // Generate a sine wave signal for 2 seconds
    for (int i = 0; i < sample_count; i++) {
        float time = (float)i / SAMPLE_RATE;
        signal[i] = sin(2 * M_PI * 5 * time) + 0.5f * sin(2 * M_PI * 50 * time); // 5 Hz + 50 Hz components
    }
}

void apply_low_pass_filter(float *input, float *output, int sample_count, int filter_size) {
    // Initialize the output signal with zero
    for (int i = 0; i < sample_count; i++) {
        output[i] = 0.0f;
    }

    // Apply a simple moving average filter
    for (int i = 0; i < sample_count; i++) {
        float sum = 0.0f;
        int count = 0;

        for (int j = 0; j < filter_size; j++) {
            if (i - j >= 0) {
                sum += input[i - j];
                count++;
            }
        }

        output[i] = sum / count; // Average over the valid samples
    }
}

void print_signal(float *signal, int sample_count) {
    // Print the first 100 samples to keep it readable
    for (int i = 0; i < sample_count && i < 100; i++) {
        printf("%d: %f\n", i, signal[i]);
    }
}