//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

// Function prototypes
void print_help();
void apply_gain(float *buffer, sf_count_t frames, float gain);
void apply_reverb(float *buffer, sf_count_t frames, float decay);
void apply_echo(float *buffer, sf_count_t frames, float delay, float gain);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_help();
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Open input audio file
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Prepare buffer for audio data
    float *buffer = malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation error.\n");
        sf_close(infile);
        return 1;
    }

    // Read audio data from the file
    sf_count_t frames_read = sf_readf_float(infile, buffer, sfinfo.frames);
    sf_close(infile);

    // Process audio: Apply Gain
    float gain = 0.5; // Change gain value as needed
    apply_gain(buffer, frames_read, gain);

    // Process audio: Apply Reverb
    float decay = 0.5; // Change decay value as needed
    apply_reverb(buffer, frames_read, decay);

    // Process audio: Apply Echo
    float delay = 0.5; // in seconds
    float echo_gain = 0.3; // Change echo gain value as needed
    apply_echo(buffer, frames_read, delay, echo_gain);

    // Open output audio file for writing
    SNDFILE *outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(buffer);
        return 1;
    }

    // Write processed audio data to the output file
    sf_count_t frames_written = sf_writef_float(outfile, buffer, frames_read);
    sf_close(outfile);

    // Cleanup
    free(buffer);
    printf("Processed %lld frames from '%s' and wrote to '%s'\n", frames_written, input_file, output_file);
    return 0;
}

void print_help() {
    printf("Usage: audio_process <input_file> <output_file>\n");
    printf("Applies gain, reverb, and echo effects to the input audio file.\n");
    printf("Ensure the input file is in WAV format.\n");
}

void apply_gain(float *buffer, sf_count_t frames, float gain) {
    for (sf_count_t i = 0; i < frames; i++) {
        buffer[i] *= gain; // Amplification factor
    }
}

void apply_reverb(float *buffer, sf_count_t frames, float decay) {
    const int delay_time = 44100; // 1 second at 44100 Hz
    float *reverb_buffer = calloc(frames + delay_time, sizeof(float));
    
    for (sf_count_t i = 0; i < frames; i++) {
        reverb_buffer[i] = buffer[i];
        if (i >= delay_time) {
            reverb_buffer[i] += decay * reverb_buffer[i - delay_time];
        }
    }

    for (sf_count_t i = 0; i < frames; i++) {
        buffer[i] = reverb_buffer[i]; // Copy over the processed data
    }

    free(reverb_buffer);
}

void apply_echo(float *buffer, sf_count_t frames, float delay, float gain) {
    int delay_samples = (int)(delay * 44100); // Convert seconds to samples
    for (sf_count_t i = delay_samples; i < frames; i++) {
        buffer[i] += gain * buffer[i - delay_samples]; // Add echo
    }
}