//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define BUFFER_SIZE 1024
#define MAX_VOLUME 0.8
#define MIN_VOLUME 0.0

// Function to apply a simple gain to the audio samples
void apply_gain(float *samples, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        samples[i] *= gain;
        if (samples[i] > MAX_VOLUME) {
            samples[i] = MAX_VOLUME;
        } else if (samples[i] < MIN_VOLUME) {
            samples[i] = MIN_VOLUME;
        }
    }
}

// Function to apply a fade-in effect to the audio samples
void apply_fade_in(float *samples, size_t num_samples, float duration, float sample_rate) {
    size_t fade_samples = (size_t)(duration * sample_rate);
    for (size_t i = 0; i < fade_samples && i < num_samples; i++) {
        float fade_factor = (float)i / fade_samples;
        samples[i] *= fade_factor;
    }
}

// Function to apply a fade-out effect to the audio samples
void apply_fade_out(float *samples, size_t num_samples, float duration, float sample_rate) {
    size_t fade_samples = (size_t)(duration * sample_rate);
    for (size_t i = 0; i < fade_samples && (num_samples - i - 1) >= 0; i++) {
        float fade_factor = (float)(fade_samples - i) / fade_samples;
        samples[num_samples - i - 1] *= fade_factor;
    }
}

// Main processing function that reads, modifies, and writes audio data
int process_audio(const char *input_file, const char *output_file, float gain, float fade_in_duration, float fade_out_duration) {
    SF_INFO sfinfo;
    SNDFILE *infile, *outfile;

    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open input file: %s\n", input_file);
        return 1;
    }

    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", output_file);
        sf_close(infile);
        return 1;
    }

    float buffer[BUFFER_SIZE];
    size_t read_count;

    while ((read_count = sf_readf_float(infile, buffer, BUFFER_SIZE)) > 0) {
        // Apply effects
        apply_gain(buffer, read_count, gain);
        if (sf_seek(infile, 0, SEEK_CUR) == 0) {
            apply_fade_in(buffer, read_count, fade_in_duration, sfinfo.samplerate);
        }
        if (sf_seek(infile, 0, SEEK_END) - read_count == 0) {
            apply_fade_out(buffer, read_count, fade_out_duration, sfinfo.samplerate);
        }

        sf_writef_float(outfile, buffer, read_count);
    }

    sf_close(infile);
    sf_close(outfile);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <gain> <fade_in_duration> <fade_out_duration>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);
    float fade_in_duration = atof(argv[4]);
    float fade_out_duration = atof(argv[5]);

    if (gain < MIN_VOLUME || gain > MAX_VOLUME) {
        fprintf(stderr, "Gain must be between %.2f and %.2f\n", MIN_VOLUME, MAX_VOLUME);
        return 1;
    }

    if (fade_in_duration < 0 || fade_out_duration < 0) {
        fprintf(stderr, "Fade durations must be non-negative.\n");
        return 1;
    }

    return process_audio(input_file, output_file, gain, fade_in_duration, fade_out_duration);
}