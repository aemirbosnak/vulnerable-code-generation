//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100  // Sample rate in Hz
#define MAX_FREQ 1000      // Maximum frequency for the sine wave
#define MAX_SAMPLES 44100  // Number of samples for 1 second

// Function to generate a sine wave signal
void generate_sine_wave(double frequency, double duration, double *buffer) {
    int samples_count = (int)(duration * SAMPLE_RATE);
    for (int i = 0; i < samples_count; i++) {
        buffer[i] = sin(2 * M_PI * frequency * (i / (double)SAMPLE_RATE));
    }
}

// Function to apply a simple low-pass filter on the signal
void low_pass_filter(double *input, double *output, int num_samples, double cutoff) {
    double RC = 1.0 / (cutoff * 2 * M_PI);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    
    output[0] = input[0];  // Initial value
    for (int i = 1; i < num_samples; i++) {
        output[i] = output[i - 1] + (alpha * (input[i] - output[i - 1]));
    }
}

// Function to normalize the audio signal between -1 and 1
void normalize(double *buffer, int num_samples) {
    double max_val = 0.0;
    for (int i = 0; i < num_samples; i++) {
        if (fabs(buffer[i]) > max_val) {
            max_val = fabs(buffer[i]);
        }
    }
    if (max_val > 0.0) {
        for (int i = 0; i < num_samples; i++) {
            buffer[i] /= max_val;
        }
    }
}

// Function to write the samples to a WAV file
void write_wav_file(const char *filename, double *data, int num_samples) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    // Write WAV header
    fwrite("RIFF", sizeof(char), 4, file);
    int chunk_size = 36 + num_samples * sizeof(short);
    fwrite(&chunk_size, sizeof(int), 1, file);
    fwrite("WAVE", sizeof(char), 4, file);
    fwrite("fmt ", sizeof(char), 4, file);
    int subchunk1_size = 16;
    fwrite(&subchunk1_size, sizeof(int), 1, file);
    short audio_format = 1;  // PCM
    fwrite(&audio_format, sizeof(short), 1, file);
    short num_channels = 1;  // Mono
    fwrite(&num_channels, sizeof(short), 1, file);
    int sample_rate = SAMPLE_RATE;
    fwrite(&sample_rate, sizeof(int), 1, file);
    int byte_rate = SAMPLE_RATE * num_channels * sizeof(short);
    fwrite(&byte_rate, sizeof(int), 1, file);
    short block_align = num_channels * sizeof(short);
    fwrite(&block_align, sizeof(short), 1, file);
    short bits_per_sample = 16;  // Bits per sample
    fwrite(&bits_per_sample, sizeof(short), 1, file);
    fwrite("data", sizeof(char), 4, file);
    int subchunk2_size = num_samples * sizeof(short);
    fwrite(&subchunk2_size, sizeof(int), 1, file);

    // Convert float samples to signed 16-bit integers
    for (int i = 0; i < num_samples; i++) {
        short sample = (short)(data[i] * 32767.0);
        fwrite(&sample, sizeof(short), 1, file);
    }
    fclose(file);
}

// Main function
int main() {
    double frequency = MAX_FREQ / 2;  // Frequency of the sine wave
    double duration = 1.0;             // Duration in seconds
    double *buffer = (double *)malloc(MAX_SAMPLES * sizeof(double));
    double *filtered_buffer = (double *)malloc(MAX_SAMPLES * sizeof(double));

    // Generate sine wave
    generate_sine_wave(frequency, duration, buffer);
    
    // Normalize the sine wave
    normalize(buffer, MAX_SAMPLES);
    
    // Apply low-pass filter
    low_pass_filter(buffer, filtered_buffer, MAX_SAMPLES, 200.0);  // Cutoff frequency: 200 Hz
    
    // Write the filtered signal to a WAV file
    write_wav_file("output.wav", filtered_buffer, MAX_SAMPLES);
    
    // Clean up
    free(buffer);
    free(filtered_buffer);
    
    printf("Sine wave generated and filtered successfully. Output written to 'output.wav'\n");
    
    return 0;
}