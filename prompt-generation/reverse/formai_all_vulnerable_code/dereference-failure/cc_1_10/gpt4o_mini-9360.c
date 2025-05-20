//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100   // Samples per second
#define DURATION 5          // Duration of signal in seconds
#define PI 3.14159265358979323846

// FIR filter coefficients for a low-pass filter
double fir_coefficients[] = {0.0044, 0.0088, 0.0132, 0.0165, 0.0179, 0.0165, 0.0132, 0.0088, 0.0044};
#define COEFF_COUNT (sizeof(fir_coefficients) / sizeof(fir_coefficients[0]))

void generate_sine_wave(double frequency, double *buffer, int length) {
    for (int i = 0; i < length; i++) {
        buffer[i] = sin(2 * PI * frequency * (i / (double)SAMPLE_RATE));
    }
}

void apply_fir_filter(double *input, double *output, int length) {
    for (int n = 0; n < length; n++) {
        output[n] = 0.0;
        for (int k = 0; k < COEFF_COUNT; k++) {
            if (n - k >= 0) {
                output[n] += fir_coefficients[k] * input[n - k];
            }
        }
    }
}

void write_to_file(const char *filename, double *data, int length) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++) {
        fprintf(file, "%lf\n", data[i]);
    }
    fclose(file);
}

int main() {
    int total_samples = SAMPLE_RATE * DURATION;
    double *input_signal = (double *)malloc(total_samples * sizeof(double));
    double *filtered_signal = (double *)malloc(total_samples * sizeof(double));

    if (!input_signal || !filtered_signal) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    printf("Generating sine wave...\n");
    generate_sine_wave(440.0, input_signal, total_samples);  // 440 Hz - A note

    printf("Applying FIR filter...\n");
    apply_fir_filter(input_signal, filtered_signal, total_samples);

    printf("Writing results to output.txt...\n");
    write_to_file("output.txt", filtered_signal, total_samples);
    
    printf("Processing complete! Filtered data written to output.txt\n");

    free(input_signal);
    free(filtered_signal);
    
    return EXIT_SUCCESS;
}