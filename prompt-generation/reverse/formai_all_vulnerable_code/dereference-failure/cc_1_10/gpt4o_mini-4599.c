//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0  // A4 note
#define DURATION 5      // duration in seconds
#define AMPLITUDE 0.5   // amplitude of the signal

void generateSineWave(float *buffer, int samples, float frequency, float amplitude) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = amplitude * sin(2.0 * M_PI * frequency * ((float)i / SAMPLE_RATE));
    }
}

void applyGain(float *buffer, int samples, float gain) {
    for (int i = 0; i < samples; i++) {
        buffer[i] *= gain;
    }
}

void generateNoise(float *buffer, int samples) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = (float)rand() / RAND_MAX * 2.0 - 1.0; // random values between -1 and 1
    }
}

void mixSignals(float *signal1, float *signal2, float *output, int samples) {
    for (int i = 0; i < samples; i++) {
        output[i] = signal1[i] + signal2[i];
        // Simple clipping to prevent distortion
        if (output[i] > 1.0) output[i] = 1.0;
        if (output[i] < -1.0) output[i] = -1.0;
    }
}

void saveWAV(const char* filename, float *buffer, int samples) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Cannot open file for writing\n");
        return;
    }

    // Write WAV header 
    fwrite("RIFF", 4, 1, file);
    unsigned int chunkSize = 36 + samples * 2;
    fwrite(&chunkSize, 4, 1, file);
    fwrite("WAVE", 4, 1, file);
    fwrite("fmt ", 4, 1, file);

    unsigned int subChunk1Size = 16;
    fwrite(&subChunk1Size, 4, 1, file);
    unsigned short audioFormat = 1;  // PCM
    fwrite(&audioFormat, 2, 1, file);
    unsigned short numChannels = 1;   // mono
    fwrite(&numChannels, 2, 1, file);
    unsigned int sampleRate = SAMPLE_RATE;
    fwrite(&sampleRate, 4, 1, file);
    unsigned int byteRate = SAMPLE_RATE * numChannels * 2;
    fwrite(&byteRate, 4, 1, file);
    unsigned short blockAlign = numChannels * 2;
    fwrite(&blockAlign, 2, 1, file);
    unsigned short bitsPerSample = 16;
    fwrite(&bitsPerSample, 2, 1, file);
    
    fwrite("data", 4, 1, file);
    unsigned int dataSize = samples * 2;
    fwrite(&dataSize, 4, 1, file);

    // Convert float to int16 and write data
    for (int i = 0; i < samples; i++) {
        short sample = (short)(buffer[i] * 32767); // Convert to int16
        fwrite(&sample, 2, 1, file);
    }

    fclose(file);
    printf("WAV file saved as %s\n", filename);
}

int main() {
    int samples = SAMPLE_RATE * DURATION;

    float *sineWave = (float *)malloc(samples * sizeof(float));
    float *noise = (float *)malloc(samples * sizeof(float));
    float *output = (float *)malloc(samples * sizeof(float));

    if (!sineWave || !noise || !output) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Generate sine wave
    generateSineWave(sineWave, samples, FREQUENCY, AMPLITUDE);
    
    // Generate noise
    generateNoise(noise, samples);
    
    // Mix signals
    mixSignals(sineWave, noise, output, samples);
    
    // Save to WAV file
    saveWAV("output.wav", output, samples);
    
    // Clean up
    free(sineWave);
    free(noise);
    free(output);

    return 0;
}