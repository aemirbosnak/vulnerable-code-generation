//FormAI DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

int main()
{
    // Initialize variables
    float frequency = 440; // A4 note frequency in Hz
    float duration = 2; // Duration of sound in seconds
    float amplitude = 0.5; // Amplitude of sound wave
    short *samples; // Array to hold audio samples
    float time_step = 1.0/SAMPLE_RATE; // Time step between samples
    int num_samples = duration * SAMPLE_RATE; // Number of samples

    // Allocate memory for samples array
    samples = malloc(sizeof(short) * num_samples);

    // Create sine wave samples
    for(int i = 0; i < num_samples; i++) {
        samples[i] = amplitude * sin(2 * PI * frequency * i * time_step);
    }

    // Write samples to WAV file
    FILE *file;
    file = fopen("output.wav", "wb");
    fprintf(file, "RIFF"); // Write WAV header
    // Write file size (Size of file = Size of data + 36 bytes for WAV header)
    fprintf(file, "%c%c%c%c", (num_samples * 2 + 36) & 0xff, ((num_samples * 2 + 36) >> 8) & 0xff, ((num_samples * 2 + 36) >> 16) & 0xff, ((num_samples * 2 + 36) >> 24) & 0xff);
    fprintf(file, "WAVEfmt "); // Write format chunk
    // Write chunk size (16 bytes for PCM)
    fprintf(file, "%c%c%c%c", 16 & 0xff, (16 >> 8) & 0xff, (16 >> 16) & 0xff, (16 >> 24) & 0xff);
    // Write audio format (1 for PCM)
    fprintf(file, "%c%c", 1 & 0xff, (1 >> 8) & 0xff);
    // Write number of channels (1 for mono)
    fprintf(file, "%c%c", 1 & 0xff, (1 >> 8) & 0xff);
    // Write sample rate
    fprintf(file, "%c%c%c%c", SAMPLE_RATE & 0xff, (SAMPLE_RATE >> 8) & 0xff, (SAMPLE_RATE >> 16) & 0xff, (SAMPLE_RATE >> 24) & 0xff);
    // Write byte rate
    fprintf(file, "%c%c%c%c", (SAMPLE_RATE * 2) & 0xff, ((SAMPLE_RATE * 2) >> 8) & 0xff, ((SAMPLE_RATE * 2) >> 16) & 0xff, ((SAMPLE_RATE * 2) >> 24) & 0xff);
    // Write block align (2 bytes per sample for mono)
    fprintf(file, "%c%c", 2 & 0xff, (2 >> 8) & 0xff);
    // Write bits per sample
    fprintf(file, "%c%c", 16 & 0xff, (16 >> 8) & 0xff);
    fprintf(file, "data"); // Write data chunk
    // Write data chunk size
    fprintf(file, "%c%c%c%c", num_samples * 2 & 0xff, (num_samples * 2 >> 8) & 0xff, (num_samples * 2 >> 16) & 0xff, (num_samples * 2 >> 24) & 0xff);
    // Write samples data
    for(int i = 0; i < num_samples; i++) {
        fprintf(file, "%c%c", samples[i] & 0xff, (samples[i] >> 8) & 0xff);
    }

    // Free memory
    free(samples);

    // Close file
    fclose(file);

    printf("Sound was generated successfully!");

    return 0;
}