//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100
#define CHANNELS 1
#define BUFFER_SIZE 4096
#define DURATION 5 // in seconds

void generate_sine_wave(float frequency, float *buffer, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = sinf(2 * M_PI * frequency * ((float)i / SAMPLE_RATE));
    }
}

int main(int argc, char *argv[]) {
    char *device = "default";
    float frequency = 440.0; // Frequency in Hz (A4 note)
    
    if (argc > 1) {
        frequency = atof(argv[1]);
    }

    // ALSA variables
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    uint8_t *buffer;
    int pcm;
    unsigned int rate = SAMPLE_RATE;
    int err;

    // Prepare the ALSA
    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "snd_pcm_open failed: %s\n", snd_strerror(err));
        return 1;
    }

    snd_pcm_hw_params_alloca(&params);
    snd_pcm_hw_params_any(handle, params);
    
    if ((err = snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
        fprintf(stderr, "snd_pcm_hw_params_set_access failed: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_FLOAT_LE)) < 0) {
        fprintf(stderr, "snd_pcm_hw_params_set_format failed: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_rate_near(handle, params, &rate, 0)) < 0) {
        fprintf(stderr, "snd_pcm_hw_params_set_rate_near failed: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params_set_channels(handle, params, CHANNELS)) < 0) {
        fprintf(stderr, "snd_pcm_hw_params_set_channels failed: %s\n", snd_strerror(err));
        return 1;
    }

    if ((err = snd_pcm_hw_params(handle, params)) < 0) {
        fprintf(stderr, "snd_pcm_hw_params failed: %s\n", snd_strerror(err));
        return 1;
    }

    // Allocate memory for buffer
    buffer = malloc(BUFFER_SIZE * sizeof(float));
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        return 1;
    }

    // Generate a sine wave
    generate_sine_wave(frequency, (float *)buffer, BUFFER_SIZE);

    // Play sound for the specified duration
    int total_samples = SAMPLE_RATE * DURATION;
    int samples_played = 0;

    while (samples_played < total_samples) {
        int samples_to_play = BUFFER_SIZE / sizeof(float);
        if (samples_played + samples_to_play > total_samples) {
            samples_to_play = total_samples - samples_played;
        }

        pcm = snd_pcm_writei(handle, buffer, samples_to_play);
        if (pcm < 0) {
            fprintf(stderr, "snd_pcm_writei failed: %s\n", snd_strerror(pcm));
            break;
        }

        samples_played += samples_to_play;
    }

    free(buffer);
    snd_pcm_drain(handle);
    snd_pcm_close(handle);

    printf("Finished playing sine wave at %.2f Hz\n", frequency);

    return 0;
}