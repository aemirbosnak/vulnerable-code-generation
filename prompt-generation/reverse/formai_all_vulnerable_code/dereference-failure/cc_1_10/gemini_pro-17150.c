//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_CHANNELS 2
#define FRAME_SIZE (NUM_CHANNELS * sizeof(float))

typedef struct {
    float *data;
    int num_frames;
} AudioBuffer;

AudioBuffer *create_audio_buffer(int num_frames) {
    AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
    buffer->data = malloc(num_frames * FRAME_SIZE);
    buffer->num_frames = num_frames;
    return buffer;
}

void free_audio_buffer(AudioBuffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void generate_sine_wave(AudioBuffer *buffer, float frequency, float amplitude) {
    for (int i = 0; i < buffer->num_frames; i++) {
        for (int channel = 0; channel < NUM_CHANNELS; channel++) {
            float sample = amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
            buffer->data[i * FRAME_SIZE + channel] = sample;
        }
    }
}

void play_audio_buffer(AudioBuffer *buffer) {
    // TODO: Implement audio playback using SDL or PortAudio
}

int main(int argc, char **argv) {
    // Parse command-line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <frequency> <amplitude> <duration>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float frequency = atof(argv[1]);
    float amplitude = atof(argv[2]);
    int duration = atoi(argv[3]);

    // Create an audio buffer
    int num_frames = duration * SAMPLE_RATE;
    AudioBuffer *buffer = create_audio_buffer(num_frames);

    // Generate a sine wave
    generate_sine_wave(buffer, frequency, amplitude);

    // Play the audio buffer
    play_audio_buffer(buffer);

    // Free the audio buffer
    free_audio_buffer(buffer);

    return EXIT_SUCCESS;
}