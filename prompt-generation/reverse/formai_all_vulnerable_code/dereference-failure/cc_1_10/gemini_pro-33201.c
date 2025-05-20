//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define PI (3.14159265358979323846)

typedef struct {
    double *samples;
    size_t num_samples;
    double sample_rate;
} audio_buffer;

audio_buffer *create_audio_buffer(double *samples, size_t num_samples, double sample_rate) {
    audio_buffer *buffer = malloc(sizeof(audio_buffer));
    buffer->samples = malloc(num_samples * sizeof(double));
    memcpy(buffer->samples, samples, num_samples * sizeof(double));
    buffer->num_samples = num_samples;
    buffer->sample_rate = sample_rate;
    return buffer;
}

void free_audio_buffer(audio_buffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

void generate_sine_wave(audio_buffer *buffer, double frequency, double amplitude) {
    for (size_t i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = amplitude * sin(2 * PI * frequency * (double)i / buffer->sample_rate);
    }
}

void generate_square_wave(audio_buffer *buffer, double frequency, double amplitude) {
    for (size_t i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = amplitude * ((i % (int)(1 / frequency * buffer->sample_rate)) < (1 / frequency * buffer->sample_rate / 2)) ? 1 : -1;
    }
}

void generate_triangle_wave(audio_buffer *buffer, double frequency, double amplitude) {
    for (size_t i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = amplitude * (1 - 2 * abs(((i % (int)(1 / frequency * buffer->sample_rate)) / (1 / frequency * buffer->sample_rate / 2)) - 0.5));
    }
}

void generate_sawtooth_wave(audio_buffer *buffer, double frequency, double amplitude) {
    for (size_t i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = amplitude * ((i % (int)(1 / frequency * buffer->sample_rate)) / (1 / frequency * buffer->sample_rate / 2));
    }
}

int main() {
    const size_t num_samples = 44100;
    const double sample_rate = 44100;
    audio_buffer *buffer = create_audio_buffer(malloc(num_samples * sizeof(double)), num_samples, sample_rate);
    generate_sine_wave(buffer, 440, 0.5);
    printf("Sine wave:\n");
    for (size_t i = 0; i < buffer->num_samples; i++) {
        printf("%f ", buffer->samples[i]);
    }
    printf("\n");
    generate_square_wave(buffer, 440, 0.5);
    printf("Square wave:\n");
    for (size_t i = 0; i < buffer->num_samples; i++) {
        printf("%f ", buffer->samples[i]);
    }
    printf("\n");
    generate_triangle_wave(buffer, 440, 0.5);
    printf("Triangle wave:\n");
    for (size_t i = 0; i < buffer->num_samples; i++) {
        printf("%f ", buffer->samples[i]);
    }
    printf("\n");
    generate_sawtooth_wave(buffer, 440, 0.5);
    printf("Sawtooth wave:\n");
    for (size_t i = 0; i < buffer->num_samples; i++) {
        printf("%f ", buffer->samples[i]);
    }
    printf("\n");
    free_audio_buffer(buffer);
    return 0;
}