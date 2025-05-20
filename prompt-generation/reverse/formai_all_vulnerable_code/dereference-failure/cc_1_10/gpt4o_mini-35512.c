//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define MAX_SAMPLES 44100
#define PI 3.14159265358979323846

typedef struct {
    double frequency;
    double amplitude;
    double duration;
} Sound;

void generate_sine_wave(double *buffer, Sound sound) {
    int samples = (int)(sound.duration * MAX_SAMPLES);
    for (int i = 0; i < samples; i++) {
        buffer[i] = sound.amplitude * sin(2 * PI * sound.frequency * ((double)i / MAX_SAMPLES));
    }
}

void apply_reverb(double *input_buffer, double *output_buffer, int sample_count, double decay) {
    for (int i = 0; i < sample_count; i++) {
        output_buffer[i] = input_buffer[i];
        if (i >= 500) {
            output_buffer[i] += decay * input_buffer[i - 500];
        }
    }
}

void save_to_file(const char *filename, double *buffer, int sample_count) {
    SF_INFO sfinfo;
    sfinfo.frames = sample_count;
    sfinfo.samplerate = MAX_SAMPLES;
    sfinfo.channels = 1;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    sf_write_double(outfile, buffer, sample_count);
    sf_close(outfile);
}

void print_intro() {
    printf("Welcome to the Mystical Audio Processing Puzzle!\n");
    printf("Let's create some sound waves and apply magic to them!\n");
}

int main() {
    print_intro();

    Sound sound1 = {440.0, 0.5, 2.0}; // A4 note
    Sound sound2 = {554.37, 0.5, 2.0}; // C#5 note

    double *buffer1 = malloc(MAX_SAMPLES * sizeof(double));
    double *buffer2 = malloc(MAX_SAMPLES * sizeof(double));
    double *reverb_buffer = malloc(MAX_SAMPLES * sizeof(double));

    if (!buffer1 || !buffer2 || !reverb_buffer) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    generate_sine_wave(buffer1, sound1);
    generate_sine_wave(buffer2, sound2);

    for (int i = 0; i < MAX_SAMPLES; i++) {
        buffer2[i] += buffer1[i] * 0.5; // Mix both waves
    }

    apply_reverb(buffer2, reverb_buffer, MAX_SAMPLES, 0.3); // Apply reverb with decay

    save_to_file("output.wav", reverb_buffer, MAX_SAMPLES);

    free(buffer1);
    free(buffer2);
    free(reverb_buffer);

    printf("The sound waves have been conjured and saved to output.wav!\n");
    return 0;
}