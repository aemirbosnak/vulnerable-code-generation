//FormAI DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Function to generate a sine wave */
void generate_sine_wave(int frequency, int duration, int sample_rate, double amplitude, short *buffer) {
    double angular_frequency = 2.0 * PI * frequency;
    double time_increment = 1.0 / sample_rate;
    double time = 0.0;

    for (int i = 0; i < duration * sample_rate; i++) {
        double sine_wave = amplitude * sin(angular_frequency * time);
        buffer[i] = (short) (sine_wave * 32767.0);
        time += time_increment;
    }
}

/* Function to add echo effect */
void add_echo(short *input_buffer, int duration, int sample_rate, double delay, double decay, short *output_buffer) {
    int delay_samples = delay * sample_rate;
    double decay_factor = decay / 100.0;

    for (int i = 0; i < duration * sample_rate; i++) {
        if (i >= delay_samples) {
            output_buffer[i] = input_buffer[i] + decay_factor * input_buffer[i - delay_samples];
        } else {
            output_buffer[i] = input_buffer[i];
        }
    }
}

int main() {
    int frequency = 440;           /* Frequency of sine wave (Hz) */
    int duration = 5;              /* Duration of sine wave (s) */
    int sample_rate = 44100;       /* Sample rate (samples per second) */
    double amplitude = 0.5;        /* Amplitude of sine wave (0.0 to 1.0) */
    double delay = 1.0;            /* Delay of echo (s) */
    double decay = 50.0;           /* Decay of echo (percentage) */
    short *input_buffer, *output_buffer;
    
    /* Allocate memory for input and output buffers */
    input_buffer = (short *) malloc(duration * sample_rate * sizeof(short));
    output_buffer = (short *) malloc(duration * sample_rate * sizeof(short));

    /* Generate sine wave */
    generate_sine_wave(frequency, duration, sample_rate, amplitude, input_buffer);

    /* Add echo effect */
    add_echo(input_buffer, duration, sample_rate, delay, decay, output_buffer);

    /* Output to standard output */
    for (int i = 0; i < duration * sample_rate; i++) {
        printf("%d\n", output_buffer[i]);
    }

    /* Free memory */
    free(input_buffer);
    free(output_buffer);
    
    return 0;
}