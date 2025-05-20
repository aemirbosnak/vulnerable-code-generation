//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex data type
typedef struct {
    float real;
    float imag;
} complex_t;

// Generate a complex tone
complex_t *generate_complex_tone(float frequency, float sample_rate, float duration) {
    int num_samples = sample_rate * duration;
    complex_t *tone = malloc(num_samples * sizeof(complex_t));

    for (int i = 0; i < num_samples; i++) {
        tone[i].real = cos(2 * M_PI * frequency * i / sample_rate);
        tone[i].imag = sin(2 * M_PI * frequency * i / sample_rate);
    }

    return tone;
}

// Apply a low-pass filter to a complex signal
complex_t *low_pass_filter(complex_t *signal, int num_samples, float cutoff_frequency, float sample_rate) {
    float alpha = 2 * M_PI * cutoff_frequency / sample_rate;
    complex_t *filtered_signal = malloc(num_samples * sizeof(complex_t));

    filtered_signal[0].real = signal[0].real;
    filtered_signal[0].imag = signal[0].imag;

    for (int i = 1; i < num_samples; i++) {
        filtered_signal[i].real = alpha * signal[i].real + (1 - alpha) * filtered_signal[i - 1].real;
        filtered_signal[i].imag = alpha * signal[i].imag + (1 - alpha) * filtered_signal[i - 1].imag;
    }

    return filtered_signal;
}

// Plot the magnitude of a complex signal
void plot_magnitude(complex_t *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        printf("%f\n", sqrt(signal[i].real * signal[i].real + signal[i].imag * signal[i].imag));
    }
}

// Main function
int main() {
    // Generate a complex tone
    complex_t *tone = generate_complex_tone(1000, 44100, 1);

    // Apply a low-pass filter to the tone
    complex_t *filtered_tone = low_pass_filter(tone, 44100, 2000, 44100);

    // Plot the magnitude of the filtered tone
    plot_magnitude(filtered_tone, 44100);

    // Free the memory allocated for the tone and the filtered tone
    free(tone);
    free(filtered_tone);

    return 0;
}