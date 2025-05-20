//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define PCM_DEVICE "default"

typedef struct {
    float *buffer;
    int size;
} AudioData;

AudioData* create_audio_data(int size) {
    AudioData *audio = (AudioData *)malloc(sizeof(AudioData));
    audio->buffer = (float *)malloc(size * sizeof(float));
    audio->size = size;
    return audio;
}

void free_audio_data(AudioData *audio) {
    free(audio->buffer);
    free(audio);
}

void fill_sine_wave(AudioData *audio, float frequency, int sample_rate) {
    for (int i = 0; i < audio->size; i++) {
        audio->buffer[i] = 0.5f * sinf(2.0f * M_PI * frequency * (float)i / (float)sample_rate);
    }
}

void reverse_audio(AudioData *audio) {
    for (int i = 0; i < audio->size / 2; i++) {
        float temp = audio->buffer[i];
        audio->buffer[i] = audio->buffer[audio->size - i - 1];
        audio->buffer[audio->size - i - 1] = temp;
    }
}

void mix_audio(AudioData *audio1, AudioData *audio2) {
    int min_size = (audio1->size < audio2->size) ? audio1->size : audio2->size;
    for (int i = 0; i < min_size; i++) {
        audio1->buffer[i] += audio2->buffer[i];
        if (audio1->buffer[i] > 1.0f) audio1->buffer[i] = 1.0f;
        if (audio1->buffer[i] < -1.0f) audio1->buffer[i] = -1.0f;
    }
}

void play_audio(AudioData *audio, int sample_rate) {
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;

    int rc = snd_pcm_open(&handle, PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0);
    if (rc < 0) {
        fprintf(stderr, "unable to open pcm device: %s\n", snd_strerror(rc));
        exit(EXIT_FAILURE);
    }

    snd_pcm_hw_params_alloca(&params);
    snd_pcm_hw_params_any(handle, params);
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_FLOAT_LE);
    snd_pcm_hw_params_set_rate_near(handle, params, &sample_rate, 0);
    snd_pcm_hw_params_set_channels(handle, params, 1);
    rc = snd_pcm_hw_params(handle, params);
    if (rc < 0) {
        fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
        exit(EXIT_FAILURE);
    }

    rc = snd_pcm_prepare(handle);
    if (rc < 0) {
        fprintf(stderr, "unable to prepare pcm device: %s\n", snd_strerror(rc));
        exit(EXIT_FAILURE);
    }

    rc = snd_pcm_writei(handle, audio->buffer, audio->size);
    if (rc < 0) {
        fprintf(stderr, "write to audio interface failed: %s\n", snd_strerror(rc));
    }

    snd_pcm_drain(handle);
    snd_pcm_close(handle);
}

int main(int argc, char *argv[]) {
    int sample_rate = 44100;
    int duration = 5; // seconds
    int size = sample_rate * duration;

    AudioData *sine_wave = create_audio_data(size);
    AudioData *reversed_wave = create_audio_data(size);
    
    fill_sine_wave(sine_wave, 440.0f, sample_rate);
    reverse_audio(sine_wave);
    
    printf("Playing reversed sine wave...\n");
    play_audio(sine_wave, sample_rate);

    mix_audio(sine_wave, reversed_wave);

    printf("Playing mixed audio...\n");
    play_audio(sine_wave, sample_rate);

    free_audio_data(sine_wave);
    free_audio_data(reversed_wave);
    return 0;
}