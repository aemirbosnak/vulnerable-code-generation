//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0
#define DURATION 5.0

void generate_sine_wave(double *buffer, int size, double frequency, double sample_rate) {
    for (int i = 0; i < size; i++) {
        buffer[i] = sin(2 * M_PI * frequency * (i / sample_rate));
    }
}

void apply_reverb(double *input, double *output, int size, double delay, double decay) {
    int delay_samples = (int)(delay * SAMPLE_RATE);
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
        if (i >= delay_samples) {
            output[i] += input[i - delay_samples] * decay;
        }
    }
}

void save_to_wav(const char *filename, double *data, int size) {
    SNDFILE *file;
    SF_INFO sfinfo;

    memset(&sfinfo, 0, sizeof(sfinfo));
    sfinfo.frames = size;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = 1;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    file = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!file) {
        fprintf(stderr, "Could not open file for writing.\n");
        exit(1);
    }

    // Convert double data to int16 for wav format
    int16_t *int_samples = (int16_t *)malloc(size * sizeof(int16_t));
    for (int i = 0; i < size; i++) {
        int_samples[i] = (int16_t)(data[i] * 32767); // Normalize to int16 range
    }

    sf_writef_short(file, int_samples, size);
    sf_close(file);
    free(int_samples);
}

int main() {
    int num_samples = (int)(SAMPLE_RATE * DURATION);
    double *sine_wave = (double *)malloc(num_samples * sizeof(double));
    double *output_with_reverb = (double *)malloc(num_samples * sizeof(double));

    // Generate a sine wave
    generate_sine_wave(sine_wave, num_samples, FREQUENCY, SAMPLE_RATE);

    // Apply reverb effect
    apply_reverb(sine_wave, output_with_reverb, num_samples, 0.1, 0.5);

    // Save output to WAV file
    save_to_wav("output_with_reverb.wav", output_with_reverb, num_samples);

    // Clean up
    free(sine_wave);
    free(output_with_reverb);

    printf("Sine wave generated and saved with reverb effect to output_with_reverb.wav\n");
    return 0;
}