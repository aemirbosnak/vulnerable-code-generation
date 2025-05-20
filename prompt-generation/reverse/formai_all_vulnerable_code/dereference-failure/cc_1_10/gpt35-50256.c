//FormAI DATASET v1.0 Category: Audio processing ; Style: Ada Lovelace
// Ada-Style Audio Processing in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define MAX_VOLUME 32767

// Function to generate a sine wave of given frequency and duration
void generate_sine_wave(double freq, double duration_ms, short *buffer)
{
    double amplitude = MAX_VOLUME / 2.0;
    int num_samples = duration_ms * SAMPLE_RATE / 1000;
    double theta_increment = freq * 2.0 * M_PI / SAMPLE_RATE;
    double theta = 0.0;
    int i;

    for (i = 0; i < num_samples; i++) {
        buffer[i] = amplitude * sin(theta);
        theta += theta_increment;
    }
}

// Function to add two waveforms
void add_waveforms(short *buffer1, short *buffer2, int num_samples)
{
    int i;

    for (i = 0; i < num_samples; i++) {
        buffer1[i] += buffer2[i];
    }
}

// Function to multiply an input buffer with a gain value
void apply_gain(short *buffer, int num_samples, double gain)
{
    int i;

    for (i = 0; i < num_samples; i++) {
        buffer[i] *= gain;
    }
}

int main()
{
    int num_samples = SAMPLE_RATE * 2;
    short *buffer1 = malloc(num_samples * sizeof(short));
    short *buffer2 = malloc(num_samples * sizeof(short));
    int i;

    // Generate a 1 kHz sine wave of 1 second duration in buffer1
    generate_sine_wave(1000.0, 1000.0, buffer1);

    // Generate a 2 kHz sine wave of 1 second duration in buffer2
    generate_sine_wave(2000.0, 1000.0, buffer2);

    // Add the two waveforms
    add_waveforms(buffer1, buffer2, num_samples);

    // Apply a gain of 0.5 to the resulting waveform
    apply_gain(buffer1, num_samples, 0.5);

    // Write the audio data to a file
    FILE *file = fopen("output.pcm", "wb");
    fwrite(buffer1, sizeof(short), num_samples, file);
    fclose(file);

    free(buffer1);
    free(buffer2);

    return 0;
}