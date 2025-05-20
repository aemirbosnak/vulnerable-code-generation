//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float *samples;
    int num_samples;
    int sample_rate;
} AudioBuffer;

AudioBuffer *new_audio_buffer(int num_samples, int sample_rate) {
    AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
    buffer->samples = malloc(num_samples * sizeof(float));
    buffer->num_samples = num_samples;
    buffer->sample_rate = sample_rate;
    return buffer;
}

void free_audio_buffer(AudioBuffer *buffer) {
    free(buffer->samples);
    free(buffer);
}

void write_audio_buffer_to_file(AudioBuffer *buffer, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(buffer->samples, sizeof(float), buffer->num_samples, fp);
    fclose(fp);
}

AudioBuffer *generate_sine_wave(float frequency, int num_samples, int sample_rate) {
    AudioBuffer *buffer = new_audio_buffer(num_samples, sample_rate);
    for (int i = 0; i < num_samples; i++) {
        buffer->samples[i] = sin(2 * M_PI * frequency * i / sample_rate);
    }
    return buffer;
}

AudioBuffer *apply_gain(AudioBuffer *buffer, float gain) {
    AudioBuffer *new_buffer = new_audio_buffer(buffer->num_samples, buffer->sample_rate);
    for (int i = 0; i < buffer->num_samples; i++) {
        new_buffer->samples[i] = buffer->samples[i] * gain;
    }
    return new_buffer;
}

AudioBuffer *add_buffers(AudioBuffer *buffer1, AudioBuffer *buffer2) {
    if (buffer1->num_samples != buffer2->num_samples) {
        fprintf(stderr, "Error: buffers must have the same number of samples\n");
        return NULL;
    }
    AudioBuffer *new_buffer = new_audio_buffer(buffer1->num_samples, buffer1->sample_rate);
    for (int i = 0; i < buffer1->num_samples; i++) {
        new_buffer->samples[i] = buffer1->samples[i] + buffer2->samples[i];
    }
    return new_buffer;
}

int main() {
    AudioBuffer *buffer1 = generate_sine_wave(440.0, 44100, 44100);
    AudioBuffer *buffer2 = generate_sine_wave(880.0, 44100, 44100);
    AudioBuffer *buffer3 = apply_gain(buffer1, 0.5);
    AudioBuffer *buffer4 = add_buffers(buffer3, buffer2);
    write_audio_buffer_to_file(buffer4, "output.wav");
    free_audio_buffer(buffer1);
    free_audio_buffer(buffer2);
    free_audio_buffer(buffer3);
    free_audio_buffer(buffer4);
    return 0;
}