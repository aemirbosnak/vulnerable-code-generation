//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 1024
#define SAMPLING_RATE 44100 // in Hz
#define PI 3.14159265358979323846

typedef struct {
    double frequency;
    double amplitude;
    double phase;
    int sampleRate;
    int samples;
    double *waveform;
} SineWave;

void generateSineWave(SineWave *wave) {
    wave->waveform = (double *)malloc(wave->samples * sizeof(double));
    if (wave->waveform == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < wave->samples; i++) {
        wave->waveform[i] = wave->amplitude * sin(2 * PI * wave->frequency * (i / (double)wave->sampleRate) + wave->phase);
    }
}

void saveToWav(const char *filename, SineWave *wave) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file for writing\n");
        exit(1);
    }

    // WAV file header
    int chunkSize = 36 + wave->samples * 2; // 2 bytes per sample for 16-bit audio
    fwrite("RIFF", 4, 1, file);
    fwrite(&chunkSize, 4, 1, file);
    fwrite("WAVE", 4, 1, file);
    fwrite("fmt ", 4, 1, file);
    int subChunk1Size = 16;
    short audioFormat = 1; // PCM
    short numChannels = 1; // Mono
    fwrite(&subChunk1Size, 4, 1, file);
    fwrite(&audioFormat, 2, 1, file);
    fwrite(&numChannels, 2, 1, file);
    fwrite(&wave->sampleRate, 4, 1, file);
    int byteRate = wave->sampleRate * numChannels * 2; // 16-bit audio
    fwrite(&byteRate, 4, 1, file);
    short blockAlign = numChannels * 2; // 16-bit audio
    fwrite(&blockAlign, 2, 1, file);
    short bitsPerSample = 16; // 16 bits
    fwrite(&bitsPerSample, 2, 1, file);
    
    fwrite("data", 4, 1, file);
    int dataSize = wave->samples * 2; // 2 bytes per sample
    fwrite(&dataSize, 4, 1, file);

    // Write audio data (16-bit signed samples)
    for (int i = 0; i < wave->samples; i++) {
        short sample = (short)(wave->waveform[i] * 32767); // Convert to 16-bit
        fwrite(&sample, 2, 1, file);
    }

    fclose(file);
    free(wave->waveform);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <filename> <frequency> <amplitude> <samples>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    double frequency = atof(argv[2]);
    double amplitude = atof(argv[3]);
    int samples = atoi(argv[4]);

    if (samples > MAX_SAMPLES) {
        fprintf(stderr, "Samples exceed maximum limit of %d\n", MAX_SAMPLES);
        return 1;
    }

    SineWave wave = {
        .frequency = frequency,
        .amplitude = amplitude,
        .phase = 0,
        .sampleRate = SAMPLING_RATE,
        .samples = samples,
        .waveform = NULL
    };

    generateSineWave(&wave);
    saveToWav(filename, &wave);

    printf("Sine wave generated and saved to %s\n", filename);
    return 0;
}