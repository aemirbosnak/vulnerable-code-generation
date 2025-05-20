//FormAI DATASET v1.0 Category: Audio processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000  // Sample rate in Hz
#define PI 3.14159265359  // Pi constant

int main()
{
    // Generate 1 second tone at 440 Hz frequency with a 0.5 amplitude
    double frequency = 440;  // in Hz
    double amplitude = 0.5;
    int samples = SAMPLE_RATE;
    double phase_increment = (2 * PI * frequency) / samples;
    double current_phase = 0.0;
    double sample_value = 0.0;
    double* buffer = (double*) malloc(sizeof(double) * samples);

    for (int i = 0; i < samples; i++) {
        sample_value = sin(current_phase);
        buffer[i] = sample_value * amplitude;
        current_phase += phase_increment;
        if (current_phase >= (2 * PI)) {
            current_phase -= (2 * PI);
        }
    }

    // Apply low pass filter with a 1000 Hz cutoff frequency
    double cutoff_frequency = 1000;
    double rc = 1.0 / (2 * PI * cutoff_frequency);
    double alpha = 1.0 / (rc * SAMPLE_RATE + 1);
    double previous_value = buffer[0];
    double low_pass_filtered_value = 0.0;
    for (int i = 1; i < samples; i++) {
        low_pass_filtered_value = (alpha * buffer[i]) + (1 - alpha) * previous_value;
        buffer[i] = low_pass_filtered_value;
        previous_value = low_pass_filtered_value;
    }

    // Apply echo with a 500 ms delay and 0.25 decay factor
    int delay_samples = (int) (0.5 * SAMPLE_RATE);
    double decay_factor = 0.25;
    double echo_sample_value = 0.0;
    double* echo_buffer = (double*) calloc(samples + delay_samples, sizeof(double));  // Allocate delay buffer with zeroes
    for (int i = 0; i < samples; i++) {
        echo_sample_value = buffer[i] + (decay_factor * echo_buffer[i + delay_samples]);
        buffer[i] = echo_sample_value;
        echo_buffer[i] = sample_value;
    }

    // Save the processed audio data to a file
    FILE* output_file = fopen("processed_audio.pcm", "wb");
    fwrite(buffer, sizeof(double), samples, output_file);
    fclose(output_file);

    free(buffer);
    free(echo_buffer);

    return 0;
}