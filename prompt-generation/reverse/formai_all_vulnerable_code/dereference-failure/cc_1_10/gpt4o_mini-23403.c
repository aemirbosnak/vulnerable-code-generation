//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define SAMPLE_RATE 100   // Number of samples per second
#define DURATION 2        // Duration in seconds
#define PI 3.14159265358979323846
#define CUT_OFF_FREQ 0.1 // Cut-off frequency as a fraction of the sample rate

typedef struct {
    double *data;
    int size;
} Signal;

Signal generate_sine_wave(double frequency) {
    int total_samples = SAMPLE_RATE * DURATION;
    Signal signal;
    signal.size = total_samples;
    signal.data = (double *)malloc(signal.size * sizeof(double));

    for (int i = 0; i < total_samples; i++) {
        double time = (double)i / SAMPLE_RATE;
        signal.data[i] = sin(2 * PI * frequency * time);
    }
    return signal;
}

Signal low_pass_filter(Signal input) {
    Signal output;
    output.size = input.size;
    output.data = (double *)malloc(output.size * sizeof(double));

    double alpha = CUT_OFF_FREQ / (CUT_OFF_FREQ + 1.0);
    output.data[0] = input.data[0]; // Initialize first sample

    for (int i = 1; i < input.size; i++) {
        output.data[i] = alpha * input.data[i] + (1.0 - alpha) * output.data[i - 1];
    }

    return output;
}

void display_signals(Signal original, Signal filtered) {
    printf("\nOriginal Signal vs Filtered Signal\n");
    printf("| Original | Filtered |\n");
    printf("|-----------|-----------|\n");

    for (int i = 0; i < original.size; i += 10) { // Display every 10th value for clarity
        int original_level = (int)(original.data[i] * 10);   // Scale for ASCII visualization
        int filtered_level = (int)(filtered.data[i] * 10);   // Scale for ASCII visualization

        // Clip levels to a range suitable for visualization
        original_level = original_level > 20 ? 20 : (original_level < -20 ? -20 : original_level);
        filtered_level = filtered_level > 20 ? 20 : (filtered_level < -20 ? -20 : filtered_level);

        // Display the original signal
        printf("| ");
        for (int j = 0; j < original_level + 20; j++) {
            printf(" ");
        }
        printf("*");
        for (int j = original_level + 20; j < 20; j++) {
            printf(" ");
        }
        printf(" | ");

        // Display the filtered signal
        for (int j = 0; j < filtered_level + 20; j++) {
            printf(" ");
        }
        printf("*");
        for (int j = filtered_level + 20; j < 20; j++) {
            printf(" ");
        }
        printf(" |\n");
    }
}

void free_signal(Signal signal) {
    free(signal.data);
}

int main() {
    double frequency = 1.0; // 1 Hz sine wave
    Signal original_signal = generate_sine_wave(frequency);
    Signal filtered_signal = low_pass_filter(original_signal);

    display_signals(original_signal, filtered_signal);

    free_signal(original_signal);
    free_signal(filtered_signal);

    return 0;
}