//FormAI DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265359
#endif

typedef struct {
    int sample_rate;
    int num_channels;
    float volume;
    float pan;
} AudioConfig;

void create_audio_config(AudioConfig *config, int sample_rate, int num_channels, float volume, float pan) {
    config->sample_rate = sample_rate;
    config->num_channels = num_channels;
    config->volume = volume;
    config->pan = pan;
}

void apply_volume(float *buffer, int num_samples, float volume) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] *= volume;
    }
}

void apply_pan(float *buffer, int num_samples, float pan) {
    for (int i = 0; i < num_samples; i += 2) {
        float left = buffer[i];
        float right = buffer[i + 1];
        buffer[i] = left * sqrtf(0.5f * (1.0f + pan));
        buffer[i + 1] = right *sqrtf (0.5f * (1.0f - pan));
    }
}

void apply_sine_wave(float *buffer, int num_samples, int sample_rate, int num_channels, float frequency) {
    float theta = 0.0f;
    float delta = 2.0f * M_PI * frequency / sample_rate;
    for (int i = 0; i < num_samples; i += num_channels) {
        buffer[i] = sinf(theta);
        if (num_channels == 2) {
            buffer[i + 1] = buffer[i];
        }
        theta += delta;
        if (theta >= 2.0f * M_PI) {
            theta -= 2.0f * M_PI;
        }
    }
}

void generate_audio(float *buffer, int num_samples, AudioConfig *config, float frequency) {
    apply_sine_wave(buffer, num_samples, config->sample_rate, config->num_channels, frequency);
    apply_volume(buffer, num_samples, config->volume);
    apply_pan(buffer, num_samples, config->pan);
}

int main(int argc, char *argv[]) {
    AudioConfig config;
    create_audio_config(&config, 44100, 2, 0.5f, 0.0f);
    int num_samples = config.sample_rate * 5;
    float *buffer = (float *) malloc(num_samples * sizeof(float) * config.num_channels);
    generate_audio(buffer, num_samples, &config, 440.0f);
    FILE *file = fopen("output.bin", "wb");
    fwrite(buffer, sizeof(float), num_samples * config.num_channels, file);
    fclose(file);
    free(buffer);
    return 0;
}