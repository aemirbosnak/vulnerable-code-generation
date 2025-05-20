//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <alsa/asoundlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 44100 // 1 second buffer
#define CHANNELS 2

typedef struct {
    float frequency;
    float amplitude;
    int duration;
} Oscillator;

void generate_sine_wave(float *buffer, int size, Oscillator oscillator) {
    for (int i = 0; i < size; ++i) {
        buffer[i] = oscillator.amplitude * sin(2.0 * M_PI * oscillator.frequency * (float)i / SAMPLE_RATE);
    }
}

void play_audio(float *buffer, int size) {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    unsigned int rate = SAMPLE_RATE;
    int dir;

    // Open the PCM device
    if (snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0) < 0) {
        fprintf(stderr, "Error opening PCM device\n");
        exit(EXIT_FAILURE);
    }

    // Allocate params
    snd_pcm_hw_params_malloc(&params);
    snd_pcm_hw_params_any(handle, params);
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_FLOAT);
    snd_pcm_hw_params_set_rate_near(handle, params, &rate, &dir);
    snd_pcm_hw_params_set_channels(handle, params, CHANNELS);
    snd_pcm_hw_params(handle, params);
    snd_pcm_hw_params_free(params);

    // Write audio data to the device
    int frames = snd_pcm_writei(handle, buffer, size / CHANNELS);
    if (frames < 0) {
        frames = snd_pcm_recover(handle, frames, 0);
    }

    // Clean up
    snd_pcm_close(handle);
}

int main(int argc, char *argv[]) {
    Oscillator oscillator;
    oscillator.frequency = 440.0f; // Default frequency A4
    oscillator.amplitude = 0.5f; // Default amplitude
    oscillator.duration = 1; // Default duration in seconds

    // Check for user input
    if (argc > 1) {
        oscillator.frequency = atof(argv[1]);
    }
    if (argc > 2) {
        oscillator.amplitude = atof(argv[2]);
    }
    if (argc > 3) {
        oscillator.duration = atoi(argv[3]);
    }

    printf("Generating a sine wave of frequency: %.2f Hz, amplitude: %.2f, for %d seconds.\n",
           oscillator.frequency, oscillator.amplitude, oscillator.duration);

    // Create a buffer to hold the audio data
    float *buffer = (float *)malloc(BUFFER_SIZE * CHANNELS * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Generate the sine wave
    generate_sine_wave(buffer, BUFFER_SIZE * CHANNELS, oscillator);

    // Play the audio
    play_audio(buffer, BUFFER_SIZE * CHANNELS * sizeof(float));

    // Clean up
    free(buffer);

    return 0;
}