//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0 // A4 note
#define DURATION 5.0 // Duration in seconds
#define AMPLITUDE 0.5 // Amplitude of the waveform

typedef struct {
    double *samples;
    int length;
} Waveform;

void generateSineWave(Waveform *wave, double frequency, double amplitude, double duration) {
    wave->length = (int)(SAMPLE_RATE * duration);
    wave->samples = (double *)malloc(wave->length * sizeof(double));

    for (int i = 0; i < wave->length; i++) {
        wave->samples[i] = amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
    }
}

void writeWAVFile(const char *filename, Waveform *wave) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write WAV header
    fputs("RIFF", file);
    int fileSize = 36 + wave->length * sizeof(double);
    fwrite(&fileSize, sizeof(int), 1, file);
    fputs("WAVE", file);
    fputs("fmt ", file);
    int subChunk1Size = 16;
    fwrite(&subChunk1Size, sizeof(int), 1, file);
    short audioFormat = 3; // Floating point
    fwrite(&audioFormat, sizeof(short), 1, file);
    short numChannels = 1; // Mono
    fwrite(&numChannels, sizeof(short), 1, file);
    int sampleRate = SAMPLE_RATE;
    fwrite(&sampleRate, sizeof(int), 1, file);
    int byteRate = SAMPLE_RATE * sizeof(double);
    fwrite(&byteRate, sizeof(int), 1, file);
    short blockAlign = sizeof(double); 
    fwrite(&blockAlign, sizeof(short), 1, file);
    short bitsPerSample = 64; // Double precision
    fwrite(&bitsPerSample, sizeof(short), 1, file);
    fputs("data", file);
    int dataSize = wave->length * sizeof(double);
    fwrite(&dataSize, sizeof(int), 1, file);

    // Write samples
    fwrite(wave->samples, sizeof(double), wave->length, file);
    
    fclose(file);
}

void freeWaveform(Waveform *wave) {
    free(wave->samples);
    wave->samples = NULL;
    wave->length = 0;
}

int main() {
    Waveform wave;
    generateSineWave(&wave, FREQUENCY, AMPLITUDE, DURATION);

    const char *filename = "sine_wave.wav";
    writeWAVFile(filename, &wave);

    printf("Generated sine wave of %.2f Hz, duration %.2f s, saved to %s\n", FREQUENCY, DURATION, filename);

    freeWaveform(&wave);
    return 0;
}