//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sndfile.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

// Function to apply a simple sine wave modulation
void apply_modulation(float *buffer, size_t frames, float frequency, float amplitude) {
    for (size_t i = 0; i < frames; i++) {
        float modulator = amplitude * sinf(2 * PI * frequency * (float)i / SAMPLE_RATE);
        buffer[i] *= modulator;
    }
}

// Function to read audio file
float *read_audio(const char *filename, sf_count_t *frames, int *channels) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(filename, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening file: %s\n", sf_strerror(NULL));
        return NULL;
    }

    *channels = sfinfo.channels;
    *frames = sfinfo.frames;

    float *buffer = malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    sf_readf_float(infile, buffer, sfinfo.frames);
    sf_close(infile);
    return buffer;
}

// Function to write audio file
void write_audio(const char *filename, float *buffer, sf_count_t frames, int channels) {
    SF_INFO sfinfo;
    sfinfo.frames = frames;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = channels;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening file: %s\n", sf_strerror(NULL));
        return;
    }

    sf_writef_float(outfile, buffer, frames);
    sf_close(outfile);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <frequency>(Hz) <amplitude>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float frequency = atof(argv[3]);
    float amplitude = atof(argv[4]);

    int channels;
    sf_count_t frames;
    float *buffer = read_audio(input_file, &frames, &channels);
    
    if (!buffer) {
        return EXIT_FAILURE;
    }

    // Apply sine wave modulation
    apply_modulation(buffer, frames * channels, frequency, amplitude);

    // Write to output file
    write_audio(output_file, buffer, frames, channels);

    free(buffer);
    printf("Processing complete. Output written to %s\n", output_file);
    return EXIT_SUCCESS;
}