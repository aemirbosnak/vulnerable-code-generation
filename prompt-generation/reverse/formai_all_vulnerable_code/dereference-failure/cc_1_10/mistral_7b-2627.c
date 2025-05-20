//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 8000.0
#define NUM_SAMPLES 1024
#define PI M_PI

// Low pass filter coefficients
const float filter_coeffs[] = {0.4886127f, 0.2341558f, 0.0727579f, 0.015625f};
const int filter_order = 4;

// Function to generate sine wave
void generate_sine_wave(float *buffer, float frequency, float duration, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = sinf(2 * PI * frequency * i / SAMPLE_RATE);
    }
}

// Function to apply low pass filter
void apply_low_pass_filter(float *input, float *output, int num_samples, const float *coeffs, int filter_order) {
    float b0 = coeffs[0], b1 = coeffs[1], b2 = coeffs[2], b3 = coeffs[3], a1 = coeffs[4], a2 = coeffs[5];

    for (int i = 0; i < num_samples; i++) {
        float sum = b0 * input[i]
                 + b1 * input[i - 1]
                 + b2 * input[i - 2]
                 + b3 * input[i - 3];

        output[i] = (a1 * output[i] + sum) / (a1 + b0);
    }
}

int main() {
    float *input_buffer = malloc(NUM_SAMPLES * sizeof(float)), *output_buffer = malloc(NUM_SAMPLES * sizeof(float));

    // Generate sine wave
    generate_sine_wave(input_buffer, 440.0, 1.0, NUM_SAMPLES);

    // Apply low pass filter
    apply_low_pass_filter(input_buffer, output_buffer, NUM_SAMPLES, filter_coeffs, filter_order);

    // Display filtered signal on console
    printf("Filtered Signal:\n");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%.4f ", output_buffer[i]);
        if ((i + 1) % 20 == 0)
            printf("\n");
    }

    free(input_buffer);
    free(output_buffer);

    return 0;
}