//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void apply_gain(float *buffer, sf_count_t num_frames, float gain) {
    for (sf_count_t i = 0; i < num_frames; i++) {
        buffer[i] *= gain;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;

    // Open the input file
    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (infile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Create buffer for audio data
    float *buffer = (float *)malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        return 1;
    }

    // Read the audio data
    sf_count_t num_frames = sf_readf_float(infile, buffer, sfinfo.frames);
    sf_close(infile);

    // Apply gain to the audio data
    apply_gain(buffer, num_frames * sfinfo.channels, gain);

    // Open the output file
    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (outfile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(buffer);
        return 1;
    }

    // Write the processed audio data
    sf_count_t num_written = sf_writef_float(outfile, buffer, num_frames);
    sf_close(outfile);

    // Clean up
    free(buffer);

    if (num_written != num_frames) {
        fprintf(stderr, "Error writing to output file\n");
        return 1;
    }

    printf("Audio processing complete, output file generated: %s\n", output_file);
    return 0;
}