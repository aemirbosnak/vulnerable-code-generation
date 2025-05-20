//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define NUM_SECONDS   (5)
#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER  (64)

#ifndef M_PI
#define M_PI  (3.14159265358979323846)
#endif

typedef struct {
    float *sine_wave;
    float frequency;
    float amplitude;
    float phase;
} SineWave;

SineWave *sine_wave_new(float frequency, float amplitude) {
    SineWave *sine_wave = (SineWave *) malloc(sizeof(SineWave));
    sine_wave->sine_wave = (float *) malloc(FRAMES_PER_BUFFER * sizeof(float));
    sine_wave->frequency = frequency;
    sine_wave->amplitude = amplitude;
    sine_wave->phase = 0.0f;
    return sine_wave;
}

void sine_wave_free(SineWave *sine_wave) {
    free(sine_wave->sine_wave);
    free(sine_wave);
}

void sine_wave_generate(SineWave *sine_wave, float *buffer, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        sine_wave->sine_wave[i] = sine_wave->amplitude * sinf(2.0f * M_PI * sine_wave->frequency * sine_wave->phase);
        sine_wave->phase += 1.0f / (SAMPLE_RATE / sine_wave->frequency);
        if (sine_wave->phase >= 1.0f) {
            sine_wave->phase -= 1.0f;
        }
    }
    memcpy(buffer, sine_wave->sine_wave, num_frames * sizeof(float));
}

int main(void) {
    PaStream *stream;
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    SineWave *sine_wave_1 = sine_wave_new(440.0f, 0.5f);
    SineWave *sine_wave_2 = sine_wave_new(880.0f, 0.5f);

    err = Pa_OpenDefaultStream(&stream, 2, 0, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    float *buffer = (float *) malloc(FRAMES_PER_BUFFER * sizeof(float) * 2);

    for (int i = 0; i < NUM_SECONDS * SAMPLE_RATE / FRAMES_PER_BUFFER; i++) {
        sine_wave_generate(sine_wave_1, buffer, FRAMES_PER_BUFFER);
        sine_wave_generate(sine_wave_2, buffer + FRAMES_PER_BUFFER, FRAMES_PER_BUFFER);
        err = Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER * 2);
        if (err != paNoError) {
            fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
            break;
        }
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        return -1;
    }

    sine_wave_free(sine_wave_1);
    sine_wave_free(sine_wave_2);
    free(buffer);

    Pa_Terminate();

    return 0;
}