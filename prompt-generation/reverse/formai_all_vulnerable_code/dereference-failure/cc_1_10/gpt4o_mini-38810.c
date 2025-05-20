//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Sample rate in Hz
#define DURATION 5        // Duration of the audio in seconds
#define FREQUENCY 440     // Frequency of the sine wave in Hz
#define PI 3.14159265358979323846
#define FILTER_CUTOFF 1000 // Low-pass filter cutoff frequency in Hz

typedef struct {
    int sample_rate;
    int bits_per_sample;
    int channels;
    int data_size;
} WAVHeader;

void generate_sine_wave(double* buffer, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0.5 * sin(2 * PI * FREQUENCY * ((double)i / SAMPLE_RATE));
    }
}

void apply_low_pass_filter(double* input, double* output, int buffer_size, double cutoff) {
    double RC = 1.0 / (2 * PI * cutoff);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    
    output[0] = input[0]; // Initialize the first sample
    for (int i = 1; i < buffer_size; i++) {
        output[i] = output[i - 1] + (alpha * (input[i] - output[i - 1]));
    }
}

void write_wav_file(const char* filename, double* buffer, int buffer_size, WAVHeader header) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Could not open the WAV file");
        return;
    }
    
    // Write WAV header
    fwrite("RIFF", 1, 4, file);
    int chunk_size = 36 + header.data_size; // File size
    fwrite(&chunk_size, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    int subchunk1_size = 16; // for PCM
    fwrite(&subchunk1_size, 4, 1, file);
    short audio_format = 1; // PCM
    fwrite(&audio_format, 2, 1, file);
    fwrite(&header.channels, 2, 1, file);
    fwrite(&header.sample_rate, 4, 1, file);
    int byte_rate = header.sample_rate * header.channels * (header.bits_per_sample / 8);
    fwrite(&byte_rate, 4, 1, file);
    short block_align = header.channels * (header.bits_per_sample / 8);
    fwrite(&block_align, 2, 1, file);
    fwrite(&header.bits_per_sample, 2, 1, file);
    fwrite("data", 1, 4, file);
    fwrite(&header.data_size, 4, 1, file);
    
    // Write samples
    for (int i = 0; i < buffer_size; i++) {
        short sample = (short)(buffer[i] * 32767); // Convert to 16-bit PCM
        fwrite(&sample, sizeof(short), 1, file);
    }

    fclose(file);
}

int main() {
    int total_samples = SAMPLE_RATE * DURATION;
    double* sine_wave = (double*)malloc(sizeof(double) * total_samples);
    double* filtered_wave = (double*)malloc(sizeof(double) * total_samples);

    // Generate a sine wave
    generate_sine_wave(sine_wave, total_samples);

    // Apply a low-pass filter
    apply_low_pass_filter(sine_wave, filtered_wave, total_samples, FILTER_CUTOFF);

    // Prepare WAV header
    WAVHeader header;
    header.sample_rate = SAMPLE_RATE;
    header.channels = 1; // Mono
    header.bits_per_sample = 16; // 16 bits
    header.data_size = total_samples * sizeof(short);

    // Write to a WAV file
    write_wav_file("output.wav", filtered_wave, total_samples, header);

    // Clean up
    free(sine_wave);
    free(filtered_wave);

    printf("WAV file 'output.wav' generated successfully!\n");
    return 0;
}