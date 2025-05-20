//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define MAX_DELAY 44100 // Maximum delay of 1 second at 44100 Hz
#define ECHO_ATENUATION 0.5 // Echo attenuation factor

void apply_echo(float *audio_data, sf_count_t frames, int delay, float decay) {
    for (sf_count_t i = delay; i < frames; i++) {
        audio_data[i] += (audio_data[i - delay] * decay);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <delay_in_ms>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int delay_in_ms = atoi(argv[3]);

    sf_count_t delay_in_samples = (delay_in_ms * 44100) / 1000; // Convert ms to samples
    if (delay_in_samples < 0 || delay_in_samples > MAX_DELAY) {
        fprintf(stderr, "Delay must be between 0 and %d ms\n", MAX_DELAY / 44.1);
        return 1;
    }

    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;

    // Open input file
    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Prepare audio data buffer
    float *audio_data = (float *)malloc(sfinfo.frames * sizeof(float));
    if (!audio_data) {
        fprintf(stderr, "Memory allocation error\n");
        sf_close(infile);
        return 1;
    }

    // Read audio data from file
    sf_count_t frames_read = sf_readf_float(infile, audio_data, sfinfo.frames);
    sf_close(infile);

    // Apply echo effect
    apply_echo(audio_data, frames_read, delay_in_samples, ECHO_ATENUATION);

    // Open output file
    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(audio_data);
        return 1;
    }

    // Write processed audio data to file
    sf_count_t frames_written = sf_writef_float(outfile, audio_data, frames_read);
    sf_close(outfile);
    free(audio_data);

    printf("Processed %d frames, output saved to %s\n", frames_written, output_file);
    
    return 0;
}