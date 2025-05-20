//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 44100

typedef struct {
    double *samples;
    int length;
} Waveform;

Waveform create_waveform(int length) {
    Waveform wave;
    wave.length = length;
    wave.samples = (double *)malloc(sizeof(double) * length);
    return wave;
}

void destroy_waveform(Waveform *wave) {
    free(wave->samples);
    wave->samples = NULL;
}

void generate_sine_wave(Waveform *wave, double frequency) {
    for (int i = 0; i < wave->length; i++) {
        wave->samples[i] = sin((2.0 * M_PI * frequency * i) / SAMPLE_RATE);
    }
}

void generate_white_noise(Waveform *wave) {
    for (int i = 0; i < wave->length; i++) {
        wave->samples[i] = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
    }
}

Waveform mix_waveforms(Waveform *wave1, Waveform *wave2, double ratio) {
    int length = wave1->length < wave2->length ? wave1->length : wave2->length;
    Waveform mixed = create_waveform(length);
    for (int i = 0; i < length; i++) {
        mixed.samples[i] = (wave1->samples[i] * ratio) + (wave2->samples[i] * (1 - ratio));
    }
    return mixed;
}

void save_waveform_to_file(Waveform *wave, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Write header for WAV file format
    fprintf(file, "RIFF");
    fseek(file, 4, SEEK_CUR);
    fprintf(file, "WAVEfmt ");
    fwrite("\x10\x00\x00\x00\x01\x00\x01\x00", 1, 16, file);
    fprintf(file, "\x44\xAC\x00\x00\x10\xb1\x02\x00");
  
    // Write samples
    fwrite(wave->samples, sizeof(double), wave->length, file);
    fclose(file);
}

void cosmic_dance_of_samples(const char *output_file) {
    Waveform sine_wave = create_waveform(NUM_SAMPLES);
    Waveform noise_wave = create_waveform(NUM_SAMPLES);

    generate_sine_wave(&sine_wave, 440.0);
    generate_white_noise(&noise_wave);

    Waveform mixed_wave = mix_waveforms(&sine_wave, &noise_wave, 0.7);
    
    save_waveform_to_file(&mixed_wave, output_file);

    printf("Cosmic dance completed, sounds have been woven into reality.\n");

    destroy_waveform(&sine_wave);
    destroy_waveform(&noise_wave);
    destroy_waveform(&mixed_wave);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <output_file.wav>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Awaking the muted spirits of sound...\n");

    cosmic_dance_of_samples(argv[1]);

    printf("Sounds have been immortalized in the echoes of your chosen filename.\n");

    return EXIT_SUCCESS;
}