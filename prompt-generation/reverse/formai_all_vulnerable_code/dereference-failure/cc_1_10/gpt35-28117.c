//FormAI DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

// 2π
#define TWO_PI (M_PI * 2.0)

// Function to generate a sin wave with a given frequency
void generateWave(double* buffer, double frequency, int bufferSize) {
    int i;
    double phaseIncrement = frequency / SAMPLE_RATE;
    double phase = 0.0;
    for (i = 0; i < bufferSize; i++) {
        buffer[i] = sin(phase * TWO_PI);
        phase += phaseIncrement;
        if (phase > 1.0) {
            phase -= 1.0;
        }
    }
}

// Function to add two audio buffers together
void addBuffers(double* buffer1, double* buffer2, double* outputBuffer, int bufferSize) {
    int i;
    for (i = 0; i < bufferSize; i++) {
        outputBuffer[i] = buffer1[i] + buffer2[i];
    }
}

int main(void) {
    // Allocate memory for input buffers
    double* buffer1 = (double*) malloc(BUFFER_SIZE * sizeof(double));
    double* buffer2 = (double*) malloc(BUFFER_SIZE * sizeof(double));
    double* outputBuffer = (double*) malloc(BUFFER_SIZE * sizeof(double));
    if (buffer1 == NULL || buffer2 == NULL || outputBuffer == NULL) {
        printf("Error: Unable to allocate memory!\n");
        return 1;
    }

    // Generate two sine waves with different frequencies
    generateWave(buffer1, 440.0, BUFFER_SIZE);
    generateWave(buffer2, 660.0, BUFFER_SIZE);

    // Add the two sine waves together
    addBuffers(buffer1, buffer2, outputBuffer, BUFFER_SIZE);

    // Write output to file
    FILE* file = fopen("output.raw", "wb");
    fwrite(outputBuffer, sizeof(double), BUFFER_SIZE, file);
    fclose(file);

    // Free memory
    free(buffer1);
    free(buffer2);
    free(outputBuffer);

    return 0;
}