//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void generate_sine_wave(double *signal, int length, double frequency, double amplitude);
void apply_low_pass_filter(double *signal, int length, double cutoff_frequency);
void display_signal(double *signal, int length);

int main() {
    int length = 1000;
    double frequency = 50.0;
    double amplitude = 1.0;
    double cutoff_frequency = 10.0;

    // Generate Sine Wave
    double *signal = (double *) malloc(length * sizeof(double));
    generate_sine_wave(signal, length, frequency, amplitude);

    // Apply Low Pass Filter
    apply_low_pass_filter(signal, length, cutoff_frequency);

    // Display Signal
    display_signal(signal, length);

    free(signal);
    return 0;
}

// Function to Generate Sine Wave
void generate_sine_wave(double *signal, int length, double frequency, double amplitude) {
    for (int i = 0; i < length; i++) {
        signal[i] = amplitude * sin(2.0 * M_PI * frequency * i / (double) length);
    }
}

// Function to Apply Low Pass Filter
void apply_low_pass_filter(double *signal, int length, double cutoff_frequency) {
    double pi = M_PI;
    double wc = 2.0 * pi * cutoff_frequency / (double) length;
    double b0 = 1.0 / (1.0 + wc / pi);
    double b1 = -2.0 * b0;
    double a0 = 1.0 + b1;
    double a1 = -2.0 * b0;

    double *x = (double *) malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        x[i] = signal[i];
    }

    for (int i = 0; i < length; i++) {
        double y0 = b0 * x[i] + b1 * x[i - 1];
        double y1 = a0 * y0 - a1 * y0;
        signal[i] = y1;
    }

    free(x);
}

// Function to Display Signal
void display_signal(double *signal, int length) {
    for (int i = 0; i < length; i++) {
        printf("%lf ", signal[i]);
    }
    printf("\n");
}