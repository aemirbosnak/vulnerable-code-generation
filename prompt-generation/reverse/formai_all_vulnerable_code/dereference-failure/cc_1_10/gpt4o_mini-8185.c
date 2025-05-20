//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100
#define DURATION 5 // in seconds
#define FREQUENCY 440 // Frequency in Hertz (A4 note)
#define BUFFER_SIZE (SAMPLE_RATE * DURATION)

// Function to generate a sine wave
void generate_sine_wave(double *buffer, int sample_count, double frequency) {
    double amplitude = 0.5; // Amplitude of the wave
    for (int i = 0; i < sample_count; i++) {
        buffer[i] = amplitude * sin((2 * M_PI * frequency * i) / SAMPLE_RATE);
    }
}

// Function to apply a simple low-pass filter
void low_pass_filter(double *input, double *output, int sample_count, double cutoff_frequency) {
    double rc = 1.0 / (2 * M_PI * cutoff_frequency);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (rc + dt);
    
    output[0] = input[0]; // Set the first sample directly
    for (int i = 1; i < sample_count; i++) {
        output[i] = output[i-1] + (alpha * (input[i] - output[i-1]));
    }
}

// Function to normalize audio samples to the range of int16
void normalize_to_int16(double *input, int16_t *output, int sample_count) {
    for (int i = 0; i < sample_count; i++) {
        output[i] = (int16_t)(input[i] * 32767);
    }
}

// Function to write audio data to a WAV file
void write_wav_file(const char *filename, int16_t *data, int sample_count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    // Write WAV header
    fwrite("RIFF", 4, 1, file);
    uint32_t file_size = 36 + sample_count * sizeof(int16_t);
    fwrite(&file_size, sizeof(file_size), 1, file);
    fwrite("WAVE", 4, 1, file);
    fwrite("fmt ", 4, 1, file);
    uint32_t fmt_chunk_size = 16;
    fwrite(&fmt_chunk_size, sizeof(fmt_chunk_size), 1, file);
    uint16_t audio_format = 1; // PCM
    fwrite(&audio_format, sizeof(audio_format), 1, file);
    uint16_t num_channels = 1; // Mono
    fwrite(&num_channels, sizeof(num_channels), 1, file);
    uint32_t sample_rate = SAMPLE_RATE;
    fwrite(&sample_rate, sizeof(sample_rate), 1, file);
    uint32_t byte_rate = SAMPLE_RATE * num_channels * sizeof(int16_t);
    fwrite(&byte_rate, sizeof(byte_rate), 1, file);
    uint16_t block_align = num_channels * sizeof(int16_t);
    fwrite(&block_align, sizeof(block_align), 1, file);
    uint16_t bits_per_sample = 16;
    fwrite(&bits_per_sample, sizeof(bits_per_sample), 1, file);
    fwrite("data", 4, 1, file);
    uint32_t data_chunk_size = sample_count * sizeof(int16_t);
    fwrite(&data_chunk_size, sizeof(data_chunk_size), 1, file);

    // Write audio samples
    fwrite(data, sizeof(int16_t), sample_count, file);
    fclose(file);
}

int main() {
    double *sine_wave_buffer = (double *)malloc(BUFFER_SIZE * sizeof(double));
    double *filtered_buffer = (double *)malloc(BUFFER_SIZE * sizeof(double));
    int16_t *final_output = (int16_t *)malloc(BUFFER_SIZE * sizeof(int16_t));

    // Generate sine wave
    generate_sine_wave(sine_wave_buffer, BUFFER_SIZE, FREQUENCY);
    
    // Apply low-pass filter with a cutoff frequency of 1000 Hz
    low_pass_filter(sine_wave_buffer, filtered_buffer, BUFFER_SIZE, 1000);
    
    // Normalize to int16
    normalize_to_int16(filtered_buffer, final_output, BUFFER_SIZE);
    
    // Write to WAV file
    write_wav_file("output.wav", final_output, BUFFER_SIZE);

    // Clean up
    free(sine_wave_buffer);
    free(filtered_buffer);
    free(final_output);

    printf("WAV file generated successfully: output.wav\n");
    return 0;
}