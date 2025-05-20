//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 1024

int main() {
    // Generate a sine wave
    double frequency = 440; // Hz
    double amplitude = 0.5;
    double phase = 0;
    double sample_rate = 44100;
    double t = 0;
    double dt = 1.0 / sample_rate;
    double *sine_wave = (double *) malloc(LENGTH * sizeof(double));
    for (int i = 0; i < LENGTH; i++) {
        sine_wave[i] = amplitude * sin(2 * M_PI * frequency * t + phase);
        t += dt;
    }

    // Apply a low-pass filter
    double cutoff_frequency = 1000; // Hz
    double *filter_coefficients = (double *) malloc(5 * sizeof(double));
    double wc = 2 * M_PI * cutoff_frequency / sample_rate;
    double w0 = 2 * M_PI * frequency / sample_rate;
    filter_coefficients[0] = 1;
    filter_coefficients[1] = -2 * cos(wc) + 1;
    filter_coefficients[2] = 1 - 2 * cos(wc);
    filter_coefficients[3] = -2 * cos(wc) + 1;
    filter_coefficients[4] = 0;
    double *filtered_wave = (double *) malloc(LENGTH * sizeof(double));
    for (int i = 0; i < LENGTH; i++) {
        double y = 0;
        for (int j = 0; j < 5; j++) {
            y += filter_coefficients[j] * sine_wave[(i - j) % LENGTH];
        }
        filtered_wave[i] = y;
    }

    // Save the filtered wave to a file
    FILE *output_file = fopen("filtered_wave.raw", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    fwrite(filtered_wave, sizeof(double), LENGTH, output_file);
    fclose(output_file);

    free(sine_wave);
    free(filter_coefficients);
    free(filtered_wave);

    return 0;
}