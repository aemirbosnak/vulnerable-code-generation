//FormAI DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Define constants */
#define PI 3.14159265358979323846

/* Define function to generate sine wave */
void generate_sine_wave(double frequency, int duration, double sample_rate, double amplitude, short int** buffer) {
    int num_samples = duration * sample_rate;
    double period = sample_rate / frequency;
    short int* wave = (short int*) malloc(sizeof(short int) * num_samples);
    int i;
    for (i=0; i<num_samples; i++) {
        double time = i / sample_rate;
        double angle = (2.0 * PI * i) / period;
        wave[i] = (short int)(amplitude * sin(angle));
    }
    *buffer = wave;
}

/* Define function to apply low-pass filter */
void apply_low_pass_filter(int num_samples, double sample_rate, short int* buffer, double cutoff_frequency) {
    int i, j;
    double rc = 1.0 / (2.0 * PI * cutoff_frequency);
    double dt = 1.0 / sample_rate;
    double alpha = dt / (rc+dt);
    double previous_value = (double)buffer[0];
    for (i=1; i<num_samples; i++) {
        double current_value = (double)buffer[i];
        double filtered_value = alpha * current_value + (1.0 - alpha) * previous_value;
        buffer[i] = (short int)filtered_value;
        previous_value = filtered_value;
    }
}

int main() {
    /* Define audio file parameters */
    double sample_rate = 44100.0;
    int duration = 5;  // seconds
    double amplitude = 32767.0;  // max amplitude for 16-bit PCM

    /* Generate sine wave */
    short int* sine_wave;
    generate_sine_wave(440.0, duration, sample_rate, amplitude, &sine_wave);

    /* Apply low-pass filter */
    double cutoff_frequency = 1000.0;  // Hz
    apply_low_pass_filter(duration*sample_rate, sample_rate, sine_wave, cutoff_frequency);

    /* Save audio file */
    FILE* output_file = fopen("filtered_sine_wave.pcm", "wb");
    fwrite(sine_wave, sizeof(short int), duration*sample_rate, output_file);
    fclose(output_file);
    printf("Audio file saved as filtered_sine_wave.pcm.\n");

    free(sine_wave);
    return 0;
}