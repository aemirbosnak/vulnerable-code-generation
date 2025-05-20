//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 0.5

// Function prototypes
void apply_reverb(float *input, float *output, int frames, float decay);
void write_output_to_file(const char *filename, float *output, int frames);

int main(int argc, char *argv[]) {
    // Check for input arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    // Open input audio file
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(argv[1], SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Prepare output buffer and file
    int frames = sfinfo.frames;
    float *input_buffer = malloc(frames * sfinfo.channels * sizeof(float));
    float *output_buffer = malloc(frames * sfinfo.channels * sizeof(float));

    // Read input audio data
    sf_readf_float(infile, input_buffer, frames);
    sf_close(infile);

    // Apply a simple reverb effect
    apply_reverb(input_buffer, output_buffer, frames * sfinfo.channels, 0.5);

    // Write processed audio to output file
    write_output_to_file(argv[2], output_buffer, frames);

    // Clean up
    free(input_buffer);
    free(output_buffer);
    
    return 0;
}

void apply_reverb(float *input, float *output, int frames, float decay) {
    // A simple reverb effect that adds a delayed version of the input
    int delay_samples = (int)(0.1 * SAMPLE_RATE); // 100ms delay
    for (int i = 0; i < frames; ++i) {
        output[i] = input[i];

        // Add delayed signal with decay
        if (i >= delay_samples) {
            output[i] += decay * input[i - delay_samples]; // Apply decay
        }

        // Limit output to avoid clipping
        if (output[i] > AMPLITUDE) {
            output[i] = AMPLITUDE;
        } else if (output[i] < -AMPLITUDE) {
            output[i] = -AMPLITUDE;
        }
    }
}

void write_output_to_file(const char *filename, float *output, int frames) {
    SF_INFO sfinfo;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfo.channels = 2; // Assuming stereo output
    sfinfo.samplerate = SAMPLE_RATE;

    // Create output audio file
    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        exit(1);
    }

    // Write output audio data
    sf_writef_float(outfile, output, frames / 2); // write for stereo
    sf_close(outfile);
}