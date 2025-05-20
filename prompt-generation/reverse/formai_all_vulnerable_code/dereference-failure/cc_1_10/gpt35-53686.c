//FormAI DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

int main() {
    printf("Oh my goodness! I can't believe what I'm about to do!\n");
    printf("I'm going to create a program that generates a sine wave!\n");

    int duration_in_seconds = 3;
    double frequency = 440.0;
    int num_samples = duration_in_seconds * SAMPLE_RATE;
    short *samples = malloc(num_samples * sizeof(short));

    int i;
    for (i = 0; i < num_samples; i++) {
        double time_in_seconds = (double) i / (double) SAMPLE_RATE;
        double sine_value = sin(2.0 * PI * frequency * time_in_seconds);
        short sample_value = (short) (sine_value * 32767);
        samples[i] = sample_value;
    }

    FILE *file = fopen("sineWave.wav", "wb");
    if (!file) {
        printf("Oh no! Something terrible has happened and I couldn't create my sound file.\n");
        return 1;
    }

    int num_channels = 1;
    int bytes_per_sample = sizeof(short);
    int subchunk2_size = num_samples * num_channels * bytes_per_sample;
    int chunk_size = 36 + subchunk2_size;

    fwrite("RIFF", 1, 4, file);
    fwrite(&chunk_size, 1, 4, file);
    fwrite("WAVE", 1, 4, file);

    fwrite("fmt ", 1, 4, file);
    int subchunk1_size = 16;
    short audio_format = 1;
    short block_align = num_channels * bytes_per_sample;
    int sample_rate = SAMPLE_RATE;
    int byte_rate = sample_rate * block_align;
    short bits_per_sample = 8 * bytes_per_sample;

    fwrite(&subchunk1_size, 1, 4, file);
    fwrite(&audio_format, 1, 2, file);
    fwrite(&num_channels, 1, 2, file);
    fwrite(&sample_rate, 1, 4, file);
    fwrite(&byte_rate, 1, 4, file);
    fwrite(&block_align, 1, 2, file);
    fwrite(&bits_per_sample, 1, 2, file);

    fwrite("data", 1, 4, file);
    fwrite(&subchunk2_size, 1, 4, file);

    fwrite(samples, num_samples, bytes_per_sample, file);

    fclose(file);
    free(samples);

    printf("Oh wow! I did it! I can't believe I actually created a sound wave!\n");

    return 0;
}