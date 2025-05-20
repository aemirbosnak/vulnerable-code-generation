//FormAI DATASET v1.0 Category: Audio processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000   // Sample rate in Hz
#define DURATION 5          // Duration of audio signal in seconds
#define AMPLITUDE 32760     // Maximum amplitude value

// Function to generate a sine wave signal
void generateSineWave(double frequency, double duration, short *buffer) {
    double omega = 2.0 * M_PI * frequency / SAMPLE_RATE;
    double t = 0.0;
    
    for (int i = 0; i < SAMPLE_RATE * duration; i++) {
        double value = AMPLITUDE * sin(t * omega);
        buffer[i] = (short)value;
        t += 1.0 / SAMPLE_RATE;
    }
}

// Function to generate a noise signal
void generateNoise(double duration, short *buffer) {
    for (int i = 0; i < SAMPLE_RATE * duration; i++) {
        double value = AMPLITUDE * ((double)rand() / RAND_MAX - 0.5); // Generate random values between -AMPLITUDE/2 and +AMPLITUDE/2
        buffer[i] = (short)value;
    }
}

// Function to apply a low-pass filter to the audio signal
void applyLowPassFilter(int cutoff, short *inputBuffer, short *outputBuffer) {
    double Rc = 1.0 / (2.0 * 3.14159 * cutoff);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (Rc + dt);
    
    outputBuffer[0] = inputBuffer[0];
    for (int i = 1; i < SAMPLE_RATE * DURATION; i++) {
        outputBuffer[i] = alpha * inputBuffer[i] + (1 - alpha) * outputBuffer[i-1];
    }
}

int main() {
    short *signalBuffer = (short*)malloc(SAMPLE_RATE * DURATION * sizeof(short));  // Allocate memory for signal buffer
    short *filteredBuffer = (short*)malloc(SAMPLE_RATE * DURATION * sizeof(short)); // Allocate memory for filtered buffer
    
    generateSineWave(1000, DURATION, signalBuffer);  // Generate a sine wave signal
    generateNoise(DURATION, signalBuffer);           // Add noise to the signal
    
    applyLowPassFilter(1000, signalBuffer, filteredBuffer); // Apply low-pass filter
    
    // Write the filtered signal to a WAV file
    FILE *file = fopen("filtered_signal.wav", "wb");
    fprintf(file, "RIFF"); // RIFF header
    fwrite("\0\0\0\0", 4, 1, file); // File size
    fprintf(file, "WAVE"); // WAVE header
    fprintf(file, "fmt "); // fmt header
    fwrite("\x10\0\0\0", 4, 1, file); // Block size
    fwrite("\x01\0", 2, 1, file); // Format code
    fwrite("\x01\0", 2, 1, file); // Number of interleaved channels
    fwrite("\x80\x3E\0\0", 4, 1, file); // Sample rate (48 kHz)
    fwrite("\x00\xF0\0\0", 4, 1, file); // Byte rate
    fwrite("\x02\0", 2, 1, file); // Block alignment
    fwrite("\x10\0", 2, 1, file); // Bits per sample
    fprintf(file, "data"); // Data header
    fwrite("\0\0\0\0", 4, 1, file); // Data size
    fwrite(filteredBuffer, SAMPLE_RATE * DURATION * sizeof(short), 1, file); // Data

    fclose(file);
    free(signalBuffer);
    free(filteredBuffer);
    
    return 0;
}