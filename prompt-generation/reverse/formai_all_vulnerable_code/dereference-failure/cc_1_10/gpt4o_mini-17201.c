//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100    // Sample rate in Hz
#define DURATION 5           // Duration in seconds
#define PI 3.14159265358979323846
#define FILTER_COEFF 0.1     // Low-pass filter coefficient

void generate_sine_wave(float *buffer, int samples, float frequency) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = sin(2 * PI * frequency * ((float)i / SAMPLE_RATE));
    }
}

void apply_low_pass_filter(float *input, float *output, int samples) {
    output[0] = input[0];  // Initialize first sample
    for (int i = 1; i < samples; i++) {
        output[i] = (1 - FILTER_COEFF) * output[i - 1] + FILTER_COEFF * input[i];
    }
}

void write_to_file(const char *filename, float *buffer, int samples) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < samples; i++) {
        fprintf(file, "%f\n", buffer[i]);
    }

    fclose(file);
    printf("Data successfully written to %s\n", filename);
}

int main() {
    int total_samples = SAMPLE_RATE * DURATION;
    float *sine_wave = (float *)malloc(total_samples * sizeof(float));
    float *filtered_wave = (float *)malloc(total_samples * sizeof(float));

    if (sine_wave == NULL || filtered_wave == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    float frequency = 440.0;  // Frequency of the sine wave (A4 note)
    printf("Generating sine wave with frequency: %.2f Hz\n", frequency);

    generate_sine_wave(sine_wave, total_samples, frequency);
    printf("Sine wave generated!\n");

    apply_low_pass_filter(sine_wave, filtered_wave, total_samples);
    printf("Low-pass filter applied!\n");

    const char *output_filename = "filtered_sine_wave.txt";
    write_to_file(output_filename, filtered_wave, total_samples);

    free(sine_wave);
    free(filtered_wave);

    printf("Processing complete! Enjoy the tranquility of the filtered signal.\n");
    return 0;
}