//LLAMA2-13B DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#define MINSTREL 440 // Middle A pitch (Hz)
#define MINSTREL_VEC [0.981, 1.02, 1.059, 1.097, 1.135, 1.174, 1.213, 1.252, 1.291, 1.331]

// Function to compute the fundamental frequency of a sound
float find_freq(float sample[], int n_samples) {
    int n_zero_crossings = 0;
    float freq = 0;
    for (int i = 0; i < n_samples; i++) {
        if (sample[i] == 0) {
            n_zero_crossings++;
        }
    }
    freq = (float)n_zero_crossings / (float)n_samples * MINSTREL;
    return freq;
}

// Function to compute the amplitude of a sound
float find_amp(float sample[], int n_samples) {
    int n_zero_crossings = 0;
    float amp = 0;
    for (int i = 0; i < n_samples; i++) {
        if (sample[i] == 0) {
            n_zero_crossings++;
        }
    }
    amp = (float)n_zero_crossings / (float)n_samples;
    return amp;
}

// Function to process an audio file
void process_audio(char *filename) {
    // Open the audio file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the audio data
    short *data = (short *)malloc(sizeof(short) * 2 * 44100); // 44100 samples * 2 channels * short (16 bits)
    short *data_float = (short *)malloc(sizeof(short) * 2 * 44100); // 44100 samples * 2 channels * float (32 bits)
    int n_samples = 0;
    int n_read = fread(data, sizeof(short), 2 * 44100, file);
    if (n_read != 2 * 44100) {
        printf("Error reading file %s\n", filename);
        return;
    }

    // Convert to float
    for (int i = 0; i < 2 * 44100; i++) {
        data_float[i] = (float)data[i] / 32767.0;
    }

    // Compute the fundamental frequency and amplitude
    float freq = find_freq(data_float, 2 * 44100);
    float amp = find_amp(data_float, 2 * 44100);

    // Print the results
    printf("Fundamental frequency: %f Hz\n", freq);
    printf("Amplitude: %f\n", amp);

    // Free memory
    free(data);
    free(data_float);

    // Close the file
    fclose(file);
}

int main() {
    char *filenames[] = {"example1.wav", "example2.wav", "example3.wav"};
    int n_files = sizeof(filenames) / sizeof(char *);

    for (int i = 0; i < n_files; i++) {
        process_audio(filenames[i]);
    }

    return 0;
}