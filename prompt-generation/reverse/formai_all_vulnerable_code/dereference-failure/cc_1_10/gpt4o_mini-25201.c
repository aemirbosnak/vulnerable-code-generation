//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define MAX_GAIN 2.0

void apply_gain(float *buffer, sf_count_t frames, float gain) {
    for (sf_count_t i = 0; i < frames; i++) {
        buffer[i] *= gain;
        if (buffer[i] > 1.0) {
            buffer[i] = 1.0; // Clipping to avoid distortion
        } else if (buffer[i] < -1.0) {
            buffer[i] = -1.0; // Clipping to avoid distortion
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file.wav> <output_file.wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);
    
    if (gain < 0.0 || gain > MAX_GAIN) {
        fprintf(stderr, "Error: Gain must be between 0.0 and %.1f\n", MAX_GAIN);
        return 1;
    }

    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;

    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return 1;
    }

    sf_count_t num_samples = sfinfo.frames * sfinfo.channels;
    float *buffer = malloc(num_samples * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Error allocating memory\n");
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    sf_count_t read_count = sf_readf_float(infile, buffer, sfinfo.frames);
    if (read_count < 0) {
        fprintf(stderr, "Error reading from input file\n");
        free(buffer);
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    apply_gain(buffer, read_count * sfinfo.channels, gain);

    sf_count_t wrote_count = sf_writef_float(outfile, buffer, read_count);
    if (wrote_count < 0) {
        fprintf(stderr, "Error writing to output file\n");
        free(buffer);
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    free(buffer);
    sf_close(infile);
    sf_close(outfile);
    printf("Successfully processed the audio with gain %.2f\n", gain);
    return 0;
}