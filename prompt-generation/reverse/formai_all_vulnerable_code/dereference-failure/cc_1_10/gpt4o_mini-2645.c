//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void process_audio(const char *input_file, const char *output_file, float volume) {
    SF_INFO sfinfo;
    SNDFILE *infile, *outfile;

    // Open input file
    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        exit(1);
    }

    // Set up the output file information
    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        exit(1);
    }

    // Allocate buffer for audio samples
    float *buffer = malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        sf_close(infile);
        sf_close(outfile);
        exit(1);
    }

    // Read from the input file
    sf_count_t frames_read = sf_readf_float(infile, buffer, sfinfo.frames);
    
    // Apply volume adjustment
    for (sf_count_t i = 0; i < frames_read * sfinfo.channels; i++) {
        buffer[i] *= volume;  // Increase the volume
    }

    // Write to the output file
    sf_count_t frames_written = sf_writef_float(outfile, buffer, frames_read);
    if (frames_written != frames_read) {
        fprintf(stderr, "Error writing to output file: %s\n", sf_strerror(outfile));
    }

    // Clean up
    free(buffer);
    sf_close(infile);
    sf_close(outfile);
    printf("Processing complete. Output written to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <volume>\n", argv[0]);
        return 1;
    }

    // Parse the volume level
    float volume = atof(argv[3]);
    
    // Ensure volume adjustment is greater than 0
    if (volume <= 0) {
        fprintf(stderr, "Volume must be greater than 0\n");
        return 1;
    }

    // Process the audio
    process_audio(argv[1], argv[2], volume);

    return 0;
}