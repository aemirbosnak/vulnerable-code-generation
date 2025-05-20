//FormAI DATASET v1.0 Category: Audio processing ; Style: enthusiastic
// Welcome to the exciting world of Audio Processing!
// This program demonstrates how to perform some basic audio processing using the C programming language.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.141592653589793238462643383279502884

typedef struct {
    uint16_t *data;
    uint32_t size;
} wave_t;

wave_t *create_sine_wave(double freq, double duration) {
    uint32_t num_samples = (uint32_t)(duration * SAMPLE_RATE);
    uint16_t *data = calloc(num_samples, sizeof(uint16_t));
    double phase_step = (freq * 2.0 * PI) / SAMPLE_RATE;
    double phase = 0.0;
    for (int i = 0; i < num_samples; i++) {
        data[i] = (uint16_t)(32767.0 * sin(phase));
        phase += phase_step;
        if (phase > (2.0 * PI)) {
            phase -= (2.0 * PI);
        }
    }
    wave_t *wave = malloc(sizeof(wave_t));
    wave->data = data;
    wave->size = num_samples;
    return wave;
}

wave_t *mix_waves(wave_t *wave1, wave_t *wave2) {
    if (wave1->size != wave2->size) {
        fprintf(stderr, "Error: wave sizes do not match\n");
        exit(EXIT_FAILURE);
    }
    wave_t *mixed_wave = malloc(sizeof(wave_t));
    mixed_wave->data = calloc(wave1->size, sizeof(uint16_t));
    mixed_wave->size = wave1->size;
    for (int i = 0; i < wave1->size; i++) {
        mixed_wave->data[i] = (wave1->data[i] + wave2->data[i]) / 2;
    }
    return mixed_wave;
}

void save_wave_to_file(wave_t *wave, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file for writing\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "RIFF");
    uint32_t chunk_size = 36 + (wave->size * 2);
    fwrite(&chunk_size, sizeof(uint32_t), 1, fp);
    fprintf(fp, "WAVE");
    fprintf(fp, "fmt ");
    uint32_t fmt_chunk_size = 16;
    fwrite(&fmt_chunk_size, sizeof(uint32_t), 1, fp);
    uint16_t audio_format = 1;
    fwrite(&audio_format, sizeof(uint16_t), 1, fp);
    uint16_t num_channels = 1;
    fwrite(&num_channels, sizeof(uint16_t), 1, fp);
    uint32_t sample_rate = SAMPLE_RATE;
    fwrite(&sample_rate, sizeof(uint32_t), 1, fp);
    uint32_t byte_rate = SAMPLE_RATE * 2;
    fwrite(&byte_rate, sizeof(uint32_t), 1, fp);
    uint16_t block_align = 2;
    fwrite(&block_align, sizeof(uint16_t), 1, fp);
    uint16_t bits_per_sample = 16;
    fwrite(&bits_per_sample, sizeof(uint16_t), 1, fp);
    fprintf(fp, "data");
    uint32_t data_chunk_size = wave->size * 2;
    fwrite(&data_chunk_size, sizeof(uint32_t), 1, fp);
    for (int i = 0; i < wave->size; i++) {
        fwrite(&wave->data[i], sizeof(uint16_t), 1, fp);
    }
    fclose(fp);
}

int main(void) {
    printf("Generating a 440Hz sine wave...\n");
    wave_t *wave1 = create_sine_wave(440.0, 1.0);
    save_wave_to_file(wave1, "wave1.wav");
    printf("Generating a 660Hz sine wave...\n");
    wave_t *wave2 = create_sine_wave(660.0, 1.0);
    save_wave_to_file(wave2, "wave2.wav");
    printf("Mixing the two waves...\n");
    wave_t *mixed_wave = mix_waves(wave1, wave2);
    save_wave_to_file(mixed_wave, "mixed.wav");
    printf("Done!\n");
    free(wave1->data);
    free(wave1);
    free(wave2->data);
    free(wave2);
    free(mixed_wave->data);
    free(mixed_wave);
    return 0;
}