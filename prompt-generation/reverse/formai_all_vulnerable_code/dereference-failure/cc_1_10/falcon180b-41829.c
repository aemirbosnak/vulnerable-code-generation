//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100
#define SAMPLE_SIZE 1024

// Function to generate a sine wave
void generate_sine_wave(float frequency, float amplitude, float phase, float* wave, int size) {
    float t, rad_freq, rad_phase;
    for (int i = 0; i < size; i++) {
        t = (float)i / SAMPLE_RATE;
        rad_freq = frequency * 2 * PI * t;
        rad_phase = phase + rad_freq * (float)i;
        wave[i] = amplitude * sin(rad_phase);
    }
}

// Function to apply a low-pass filter
void low_pass_filter(float* wave, int size, float cutoff_frequency) {
    float b0 = 1;
    float b1 = -2 * cutoff_frequency / PI;
    float a1 = 1 - b1;
    float y[size];
    for (int i = 0; i < size; i++) {
        y[i] = b0 * wave[i] + b1 * wave[i - 1] - a1 * y[i - 1];
        wave[i] = y[i];
    }
}

int main() {
    float frequency = 440;
    float amplitude = 0.5;
    float phase = 0;
    float cutoff_frequency = 2000;
    float* wave = (float*)malloc(SAMPLE_SIZE * sizeof(float));

    // Generate a sine wave
    generate_sine_wave(frequency, amplitude, phase, wave, SAMPLE_SIZE);

    // Apply a low-pass filter
    low_pass_filter(wave, SAMPLE_SIZE, cutoff_frequency);

    // Save the filtered wave to a file
    FILE* output_file = fopen("filtered_wave.raw", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    fwrite(wave, sizeof(float), SAMPLE_SIZE, output_file);
    fclose(output_file);

    return 0;
}