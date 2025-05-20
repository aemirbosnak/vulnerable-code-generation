//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define SAMPLE_RATE 44100
#define DURATION 1
#define PI 3.14159265358979323846
#define LOW_PASS_FACTOR 0.1
#define AMPLITUDE 30

void generate_sine_wave(float *buffer, float frequency, int length) {
    for (int i = 0; i < length; ++i) {
        buffer[i] = AMPLITUDE * sin(2 * PI * frequency * (i / (float)SAMPLE_RATE));
    }
}

void apply_low_pass_filter(float *input, float *output, int length) {
    output[0] = input[0]; // Start with the first value
    for (int i = 1; i < length; ++i) {
        output[i] = LOW_PASS_FACTOR * input[i] + (1 - LOW_PASS_FACTOR) * output[i - 1];
    }
}

void print_waveform(float *buffer, int length) {
    for (int i = 0; i < length; ++i) {
        int height = (int)(buffer[i] + AMPLITUDE);
        if (height >= 0 && height <= 2 * AMPLITUDE) {
            for (int j = 0; j < height; j++) {
                if (j == 2 * AMPLITUDE) {
                    printf("|"); // For highest point
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int num_samples = SAMPLE_RATE * DURATION;
    float *sine_wave = (float *)malloc(num_samples * sizeof(float));
    float *filtered_wave = (float *)malloc(num_samples * sizeof(float));

    printf("Prepare to be amazed by the beautiful sine wave transformation!\n");
    
    // Dynamically changing frequency
    for (float frequency = 220.0; frequency <= 440.0; frequency += 20.0) {
        generate_sine_wave(sine_wave, frequency, num_samples);
        apply_low_pass_filter(sine_wave, filtered_wave, num_samples);

        printf("Frequency: %.1f Hz\n", frequency);
        printf("Sine Wave:\n");
        print_waveform(sine_wave, num_samples / 10); // Print a smaller portion to fit console
        
        printf("Filtered Wave:\n");
        print_waveform(filtered_wave, num_samples / 10); // Print a smaller portion
        
        printf("Press Ctrl+C to stop or wait for the next frequency change...\n");
        usleep(500000); // Sleep for 0.5 seconds before the next wave
    }

    free(sine_wave);
    free(filtered_wave);
    
    printf("What a mesmerizing display of sound transformation! Exiting...\n");
    return 0;
}