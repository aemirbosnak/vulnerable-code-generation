//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQ 440

void generate_sine_wave(float* buffer, int num_samples) {
    float phase = 0;
    for (int i = 0; i < num_samples; i++) {
        float sample = sin(2 * M_PI * FREQ * phase / SAMPLE_RATE);
        buffer[i] = sample;
        phase += 2 * M_PI * FREQ / SAMPLE_RATE;
    }
}

void add_reverb(float* buffer, int num_samples, float decay) {
    float* reverb_buffer = malloc(num_samples * sizeof(float));
    for (int i = 0; i < num_samples; i++) {
        reverb_buffer[i] = 0;
    }

    for (int i = 0; i < num_samples; i++) {
        float sample = buffer[i];
        reverb_buffer[i] += sample * decay;
        for (int j = 1; j < num_samples; j++) {
            reverb_buffer[i + j] += sample * decay * (1 - decay);
        }
    }

    for (int i = 0; i < num_samples; i++) {
        buffer[i] += reverb_buffer[i];
    }

    free(reverb_buffer);
}

void main() {
    int num_samples = SAMPLE_RATE / FREQ;
    float* buffer = malloc(num_samples * sizeof(float));

    generate_sine_wave(buffer, num_samples);
    add_reverb(buffer, num_samples, 0.5);

    FILE* output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fwrite(buffer, sizeof(float), num_samples, output_file);

    fclose(output_file);
    free(buffer);
}