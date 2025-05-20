//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0
#define DURATION 2.0
#define PI 3.14159265358979323846

// Structure to hold audio signal data
typedef struct {
    double* samples;
    int length;
} Signal;

// Function to create a new audio signal with a given frequency and duration
Signal* createSineWave(double frequency, double duration) {
    int length = (int)(SAMPLE_RATE * duration);
    Signal* signal = (Signal*)malloc(sizeof(Signal));
    signal->samples = (double*)malloc(length * sizeof(double));
    signal->length = length;

    for (int i = 0; i < length; i++) {
        signal->samples[i] = 0.5 * sin(2 * PI * frequency * (i / (double)SAMPLE_RATE));
    }

    return signal;
}

// Function to apply a gain to the audio samples
void applyGain(Signal* signal, double gain) {
    for (int i = 0; i < signal->length; i++) {
        signal->samples[i] *= gain;
    }
}

// Function to write the audio signal to a WAV file
void writeWavFile(const char* filename, Signal* signal) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    // Write WAV header
    fprintf(file, "RIFF");
    fwrite(&(int){36 + signal->length * sizeof(short)}, sizeof(int), 1, file);
    fprintf(file, "WAVEfmt ");
    fwrite(&(int){16}, sizeof(int), 1, file); // Subchunk1Size
    fwrite(&(short){1}, sizeof(short), 1, file); // AudioFormat (PCM)
    fwrite(&(short){1}, sizeof(short), 1, file); // NumChannels
    fwrite(&(int){SAMPLE_RATE}, sizeof(int), 1, file); // SampleRate
    fwrite(&(int){SAMPLE_RATE * sizeof(short)}, sizeof(int), 1, file); // ByteRate
    fwrite(&(short){sizeof(short)}, sizeof(short), 1, file); // BlockAlign
    fwrite(&(short){16}, sizeof(short), 1, file); // BitsPerSample

    // Write "data" subchunk
    fprintf(file, "data");
    fwrite(&(int){signal->length * sizeof(short)}, sizeof(int), 1, file);

    // Write samples
    for (int i = 0; i < signal->length; i++) {
        short sample = (short)(signal->samples[i] * 32767);
        fwrite(&sample, sizeof(short), 1, file);
    }

    fclose(file);
    printf("Yay! The WAV file has been created successfully: %s\n", filename);
}

// Function to free signal memory
void freeSignal(Signal* signal) {
    free(signal->samples);
    free(signal);
}

int main() {
    printf("🎵 Welcome to the Magical Sine Wave Generator! 🎶\n");

    // Create a sine wave signal
    Signal* sineWave = createSineWave(FREQUENCY, DURATION);
    
    // Apply gain
    double gain = 0.8;
    applyGain(sineWave, gain);
    
    // Write the signal to a WAV file
    const char* filename = "sine_wave.wav";
    writeWavFile(filename, sineWave);
    
    // Free memory
    freeSignal(sineWave);
    
    printf("✨ Thanks for using the Magical Sine Wave Generator! ✨\n");
    return 0;
}