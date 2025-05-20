//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
// Example program for audio processing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for program
#define SAMPLE_RATE 44100
#define PI 3.14159265

// Function prototypes
double* generate_sine_wave(int frequency, double duration);
double* apply_volume(double* buffer, int buffer_size, double volume);

int main() {

    // Generate a sine wave with frequency 440 Hz and duration 1 second
    double* sine_wave = generate_sine_wave(440, 1);
    
    // Apply a volume of 0.5 to the sine wave
    double* sine_wave_half_volume = apply_volume(sine_wave, SAMPLE_RATE, 0.5);

    // Write the audio buffer to a file
    FILE* audio_file = fopen("sine_wave_half_volume.raw", "wb");
    fwrite(sine_wave_half_volume, sizeof(double), SAMPLE_RATE, audio_file);
    fclose(audio_file);

    // Free memory for audio buffers
    free(sine_wave);
    free(sine_wave_half_volume);

    return 0;
}

// Function to generate a sine wave with a given frequency and duration
double* generate_sine_wave(int frequency, double duration) {

    // Calculate number of samples based on sample rate and duration
    int num_samples = SAMPLE_RATE * duration;

    // Allocate memory for audio buffer
    double* buffer = (double*) malloc(num_samples * sizeof(double));

    // Calculate angular frequency from frequency
    double angular_frequency = 2 * PI * frequency;

    // Generate sine wave by computing sample value at each time step
    for (int i = 0; i < num_samples; i++) {
        double time = i / (double)SAMPLE_RATE;
        buffer[i] = sin(angular_frequency * time);
    }

    return buffer;
}

// Function to apply a volume to an audio buffer
double* apply_volume(double* buffer, int buffer_size, double volume) {

    // Allocate memory for new buffer
    double* new_buffer = (double*) malloc(buffer_size * sizeof(double));

    // Apply volume to each sample in the buffer
    for (int i = 0; i < buffer_size; i++) {
        new_buffer[i] = buffer[i] * volume;
    }

    return new_buffer;
}