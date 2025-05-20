//FormAI DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(float *buffer, int bufferSize, float frequency, float amplitude, float samplingRate) {
    for (int i = 0; i < bufferSize; i++) {
        float time = (float)i / samplingRate;
        buffer[i] = amplitude * sin(2 * PI * frequency * time);
    }
}

// Function to apply an amplitude envelope to the generated signal
void applyAmplitudeEnvelope(float *buffer, int bufferSize, float attackTime, float releaseTime, float sustainLevel, float samplingRate) {
    // Calculate the time constants
    float attackTimeConstant = -1 / (attackTime * samplingRate);
    float releaseTimeConstant = -1 / (releaseTime * samplingRate);

    // Initialize the envelope value and increment
    float envelope = 0.0;
    float envelopeIncrement = 1.0 / bufferSize;

    for (int i = 0; i < bufferSize; i++) {
        if (i < attackTime * samplingRate) {
            // If in the attack phase, apply an exponential envelope
            envelope = exp(i * attackTimeConstant);
        }
        else if (i >= (attackTime + releaseTime) * samplingRate) {
            // If in the release phase, apply another exponential envelope
            envelope = exp(-i * releaseTimeConstant);
        }
        else {
            // If in the sustain phase, maintain the sustain level
            envelope = sustainLevel;
        }

        // Apply the envelope to the signal
        buffer[i] *= envelope * envelopeIncrement;
    }
}

int main() {
    int bufferSize = 44100; // 1 second
    float frequency = 440.0; // A4 note
    float amplitude = 0.5; // half volume
    float samplingRate = 44100.0; // 44.1 kHz
    float attackTime = 0.1; // 100 ms
    float releaseTime = 0.2; // 200 ms
    float sustainLevel = 0.3; // 30% volume

    // Allocate memory for the signal buffer
    float *buffer = (float *)malloc(sizeof(float) * bufferSize);

    // Generate the sine wave signal
    generateSineWave(buffer, bufferSize, frequency, amplitude, samplingRate);

    // Apply the amplitude envelope to the signal
    applyAmplitudeEnvelope(buffer, bufferSize, attackTime, releaseTime, sustainLevel, samplingRate);

    // Write the signal to a file
    FILE *file = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(float), bufferSize, file);
    fclose(file);

    // Free the memory
    free(buffer);

    return 0;
}