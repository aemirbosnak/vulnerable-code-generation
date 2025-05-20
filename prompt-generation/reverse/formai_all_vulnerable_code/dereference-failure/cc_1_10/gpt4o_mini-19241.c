//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846
#define BUFFER_SIZE 1024
#define FREQUENCY 440.0  // Frequency in Hz for a sine wave
#define DURATION 5       // Duration of audio in seconds

// Function to generate a sine wave
void generate_sine_wave(float *buffer, int size, float frequency, float sample_rate) {
    for (int i = 0; i < size; i++) {
        buffer[i] = 0.5f * sinf(2.0f * PI * frequency * ((float)i / sample_rate));
    }
}

// Function to apply a simple amplitude modulation
void apply_amplitude_modulation(float *buffer, int size, float modulation_frequency, float sample_rate) {
    for (int i = 0; i < size; i++) {
        float modulation = 0.5f * (1.0f + sinf(2.0f * PI * modulation_frequency * ((float)i / sample_rate)));
        buffer[i] *= modulation;
    }
}

int main() {
    SNDFILE *outfile;
    SF_INFO sfinfo;
    float *buffer = (float *)malloc(BUFFER_SIZE * sizeof(float));
    float frequency = FREQUENCY;
    float modulation_frequency = 5.0f; // Modulation frequency

    // Setup audio file format
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.frames = 0;
    sfinfo.channels = 1; // Mono
    sfinfo.format = SF_FORMAT_PCM_16 | SF_FORMAT_WAV;

    // Create output file
    outfile = sf_open("output.wav", SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file.\n");
        return 1;
    }

    // Fill the audio buffer and write to file
    int total_samples = SAMPLE_RATE * DURATION;
    for (int num_samples_written = 0; num_samples_written < total_samples; num_samples_written += BUFFER_SIZE) {
        int samples_to_write = (num_samples_written + BUFFER_SIZE > total_samples) ? 
                               (total_samples - num_samples_written) : BUFFER_SIZE;

        generate_sine_wave(buffer, samples_to_write, frequency, SAMPLE_RATE);
        apply_amplitude_modulation(buffer, samples_to_write, modulation_frequency, SAMPLE_RATE);
        
        sf_writef_float(outfile, buffer, samples_to_write);
    }

    // Clean up
    sf_close(outfile);
    free(buffer);
    printf("Audio processing complete. Output saved as output.wav.\n");

    return 0;
}