//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define FREQUENCY 440.0 // A4 frequency
#define PI 3.14159265358979323846
#define SAMPLE_COUNT (SAMPLE_RATE * DURATION)

// Function to generate a sine wave
void generate_sine_wave(float *buffer, int sample_count, float frequency, int sample_rate) {
    for (int i = 0; i < sample_count; i++) {
        buffer[i] = sin(2 * PI * frequency * i / sample_rate);
    }
}

// Function to apply a simple low-pass filter
void low_pass_filter(float *input, float *output, int sample_count, float alpha) {
    output[0] = input[0]; // first sample remains unchanged
    for (int i = 1; i < sample_count; i++) {
        output[i] = alpha * input[i] + (1 - alpha) * output[i - 1];
    }
}

// Function to normalize audio samples
void normalize(float *buffer, int sample_count) {
    float max_val = 0;
    for (int i = 0; i < sample_count; i++) {
        if (fabs(buffer[i]) > max_val) {
            max_val = fabs(buffer[i]);
        }
    }
    if (max_val > 0) {
        for (int i = 0; i < sample_count; i++) {
            buffer[i] /= max_val;
        }
    }
}

// Function to write samples to a WAV file
void write_wav(const char *filename, float *samples, int sample_count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s for writing\n", filename);
        return;
    }

    // WAV file header
    fwrite("RIFF", 1, 4, file);
    uint32_t chunk_size = 36 + sample_count * sizeof(int16_t); // file size
    fwrite(&chunk_size, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    uint32_t subchunk1_size = 16; // PCM chunk size
    fwrite(&subchunk1_size, 4, 1, file);
    uint16_t audio_format = 1; // PCM
    fwrite(&audio_format, 2, 1, file);
    uint16_t num_channels = 1; // mono
    fwrite(&num_channels, 2, 1, file);
    fwrite(&(uint32_t){SAMPLE_RATE}, 4, 1, file);
    fwrite(&(uint32_t){SAMPLE_RATE * num_channels * sizeof(int16_t)}, 4, 1, file);
    uint16_t block_align = num_channels * sizeof(int16_t);
    fwrite(&block_align, 2, 1, file);
    uint16_t bits_per_sample = 16; // bits per sample
    fwrite(&bits_per_sample, 2, 1, file);
    fwrite("data", 1, 4, file);
    uint32_t data_size = sample_count * sizeof(int16_t);
    fwrite(&data_size, 4, 1, file);

    // Write samples
    for (int i = 0; i < sample_count; i++) {
        int16_t sample = (int16_t)(samples[i] * 32767); // convert to 16-bit integer
        fwrite(&sample, sizeof(sample), 1, file);
    }

    fclose(file);
    printf("WAV file '%s' written successfully!\n", filename);
}

int main() {
    // Allocate memory for samples
    float *sine_wave = (float *)malloc(SAMPLE_COUNT * sizeof(float));
    float *filtered_wave = (float *)malloc(SAMPLE_COUNT * sizeof(float));

    // Generate the sine wave
    printf("Generating sine wave...\n");
    generate_sine_wave(sine_wave, SAMPLE_COUNT, FREQUENCY, SAMPLE_RATE);
    
    // Normalize the generated wave
    printf("Normalizing audio samples...\n");
    normalize(sine_wave, SAMPLE_COUNT);

    // Apply a low-pass filter to the sine wave
    printf("Applying low-pass filter...\n");
    low_pass_filter(sine_wave, filtered_wave, SAMPLE_COUNT, 0.1f); // alpha = 0.1

    // Specify the output WAV file name
    char *output_filename = "sine_wave.wav";

    // Write the filtered wave to a WAV file
    write_wav(output_filename, filtered_wave, SAMPLE_COUNT);

    // Clean up
    free(sine_wave);
    free(filtered_wave);

    printf("Digital Signal Processing example completed successfully!\n");
    return 0;
}