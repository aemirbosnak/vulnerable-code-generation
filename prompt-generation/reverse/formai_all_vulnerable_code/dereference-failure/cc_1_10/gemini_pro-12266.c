//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    float *data;
    size_t length;
} Signal;

Signal *create_signal(size_t length) {
    Signal *signal = malloc(sizeof(Signal));
    signal->data = malloc(length * sizeof(float));
    signal->length = length;
    return signal;
}

void destroy_signal(Signal *signal) {
    free(signal->data);
    free(signal);
}

void generate_sine_wave(Signal *signal, float frequency, float amplitude) {
    for (size_t i = 0; i < signal->length; i++) {
        signal->data[i] = amplitude * sin(2 * PI * frequency * i / signal->length);
    }
}

void apply_filter(Signal *signal, float *kernel, size_t kernel_length) {
    float *filtered_data = malloc(signal->length * sizeof(float));

    for (size_t i = 0; i < signal->length; i++) {
        float sum = 0.0f;

        for (size_t j = 0; j < kernel_length; j++) {
            if (i - j >= 0) {
                sum += kernel[j] * signal->data[i - j];
            }
        }

        filtered_data[i] = sum;
    }

    memcpy(signal->data, filtered_data, signal->length * sizeof(float));
    free(filtered_data);
}

int main() {
    // Create a signal
    Signal *signal = create_signal(1024);

    // Generate a sine wave
    generate_sine_wave(signal, 100.0f, 1.0f);

    // Create a kernel
    float kernel[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
    size_t kernel_length = sizeof(kernel) / sizeof(float);

    // Apply the filter
    apply_filter(signal, kernel, kernel_length);

    // Print the filtered signal
    for (size_t i = 0; i < signal->length; i++) {
        printf("%f ", signal->data[i]);
    }
    printf("\n");

    // Destroy the signal
    destroy_signal(signal);

    return 0;
}