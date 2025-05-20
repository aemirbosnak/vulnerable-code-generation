//FormAI DATASET v1.0 Category: Audio processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

// Function to calculate sine wave at given frequency and sample rate
void generate_sine_wave(float *buffer, float frequency, float sample_rate, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = sin(2 * PI * frequency * i / sample_rate);
    }
}

// Function to apply Low-pass filter to signal
void apply_lowpass_filter(float *buffer, float cutoff_frequency, float sample_rate, int buffer_size) {
    float RC = 1 / (2 * PI * cutoff_frequency);
    float dt = 1 / sample_rate;
    float alpha = dt / (RC + dt);
    float previous_value = buffer[0];

    for (int i = 1; i < buffer_size; i++) {
        float current_value = buffer[i];
        buffer[i] = alpha * current_value + (1 - alpha) * previous_value;
        previous_value = buffer[i];
    }
}

int main() {
    // Allocate memory for buffer
    float *buffer = (float *)malloc(sizeof(float) * BUFFER_SIZE);

    // Generate a 440 Hz sine wave at 44100 Hz sampling rate
    generate_sine_wave(buffer, 440, 44100, BUFFER_SIZE);

    // Apply low-pass filter with cutoff frequency of 200 Hz
    apply_lowpass_filter(buffer, 200, 44100, BUFFER_SIZE);

    // Output filtered signal to file
    FILE *output_file = fopen("filtered_signal.txt", "w");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        fprintf(output_file, "%f\n", buffer[i]);
    }
    fclose(output_file);

    // Free memory
    free(buffer);

    return 0;
}