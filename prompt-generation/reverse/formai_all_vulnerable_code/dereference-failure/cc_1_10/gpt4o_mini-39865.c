//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100
#define DURATION 2.0
#define FREQUENCY 440.0

// Function to generate an audio signal (sine wave in this case)
void generate_sine_wave(float *buffer, int length, float frequency, float sample_rate) {
    for (int i = 0; i < length; i++) {
        buffer[i] = 0.5f * sinf(2.0f * M_PI * frequency * (i / sample_rate));
    }
}

// Function to apply a simple low-pass filter to the signal
void low_pass_filter(float *input, float *output, int length, float alpha) {
    output[0] = input[0]; // Initialize first sample
    for (int i = 1; i < length; i++) {
        output[i] = alpha * input[i] + (1.0f - alpha) * output[i - 1];
    }
}

// Function to write the audio data to a WAV file
void write_wav(const char *filename, float *data, int length, int sample_rate) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to create WAV file");
        exit(EXIT_FAILURE);
    }

    // WAV header
    fwrite("RIFF", 1, 4, file);
    int file_size = 36 + length * sizeof(float);
    fwrite(&file_size, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    int fmt_chunk_size = 16;
    fwrite(&fmt_chunk_size, 4, 1, file);
    short audio_format = 3; // 32-bit float
    fwrite(&audio_format, 2, 1, file);
    short num_channels = 1;
    fwrite(&num_channels, 2, 1, file);
    fwrite(&sample_rate, 4, 1, file);
    int byte_rate = sample_rate * num_channels * sizeof(float);
    fwrite(&byte_rate, 4, 1, file);
    short block_align = num_channels * sizeof(float);
    fwrite(&block_align, 2, 1, file);
    short bits_per_sample = 32;
    fwrite(&bits_per_sample, 2, 1, file);
    fwrite("data", 1, 4, file);
    int data_size = length * sizeof(float);
    fwrite(&data_size, 4, 1, file);
    
    // Write audio data
    fwrite(data, sizeof(float), length, file);

    fclose(file);
}

// Main function
int main() {
    int length = (int)(SAMPLE_RATE * DURATION);
    float *sine_wave = (float *)malloc(length * sizeof(float));
    float *filtered_signal = (float *)malloc(length * sizeof(float));

    if (!sine_wave || !filtered_signal) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    // Generate sine wave
    generate_sine_wave(sine_wave, length, FREQUENCY, SAMPLE_RATE);

    // Apply low-pass filter
    float alpha = 0.1f; // Filter coefficient
    low_pass_filter(sine_wave, filtered_signal, length, alpha);

    // Write the processed signal to a WAV file
    write_wav("sine_wave.wav", filtered_signal, length, SAMPLE_RATE);

    // Clean up
    free(sine_wave);
    free(filtered_signal);

    printf("Sine wave generated and saved as sine_wave.wav\n");

    return EXIT_SUCCESS;
}