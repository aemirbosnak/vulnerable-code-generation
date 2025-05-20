//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define DURATION 5  // duration in seconds
#define MAX_AMPLITUDE 32767

void create_sine_wave(float *buffer, int length, float frequency) {
    for (int i = 0; i < length; i++) {
        buffer[i] = (float)(sin((2 * M_PI * frequency * i) / SAMPLE_RATE) * MAX_AMPLITUDE);
    }
}

void mix_audio(float *output, float *audio1, float *audio2, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = (audio1[i] + audio2[i]) / 2; // A love that is shared equally
    }
}

void save_audio(const char *filename, float *buffer, int length) {
    SF_INFO sfinfo;
    sfinfo.channels = 1;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    sf_write_float(outfile, buffer, length);
    sf_close(outfile);
}

int main() {
    int length = SAMPLE_RATE * DURATION;  // total samples
    float *romeo_signal = (float *)malloc(length * sizeof(float));
    float *juliet_signal = (float *)malloc(length * sizeof(float));
    float *mixed_signal = (float *)malloc(length * sizeof(float));

    // Create sine waves representing Romeo and Juliet
    create_sine_wave(romeo_signal, length, 440.0f); // A4 note
    create_sine_wave(juliet_signal, length, 554.37f); // C#5 note (sweet harmony)

    // Mix the two signals
    mix_audio(mixed_signal, romeo_signal, juliet_signal, length);

    // Save the output to a WAV file
    save_audio("romeo_and_juliet.wav", mixed_signal, length);

    // Free allocated memory
    free(romeo_signal);
    free(juliet_signal);
    free(mixed_signal);

    printf("The love song of Romeo and Juliet has been composed and saved!\n");
    return 0;
}