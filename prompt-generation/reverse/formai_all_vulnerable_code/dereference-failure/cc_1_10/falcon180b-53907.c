//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

int main() {
    FILE *inputFile, *outputFile;
    short inputBuffer[BUFFER_SIZE];
    short outputBuffer[BUFFER_SIZE];
    int i, j;
    float frequency, amplitude, phase, cosine, sine;

    inputFile = fopen("input.wav", "rb");
    outputFile = fopen("output.wav", "wb");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Read header from input file
    fseek(inputFile, 0, SEEK_SET);
    fread(&frequency, sizeof(float), 1, inputFile);
    fread(&amplitude, sizeof(float), 1, inputFile);
    fread(&phase, sizeof(float), 1, inputFile);

    // Initialize cosine and sine values
    cosine = cos(2 * PI * frequency);
    sine = sin(2 * PI * frequency);

    while (fread(inputBuffer, sizeof(short), BUFFER_SIZE, inputFile) == BUFFER_SIZE) {
        // Apply filter
        for (i = 0; i < BUFFER_SIZE; i++) {
            outputBuffer[i] = (short) (amplitude * (cosine * inputBuffer[i] - sine * phase) + phase);
            phase += frequency;
            if (phase >= 2 * PI) {
                phase -= 2 * PI;
            }
        }

        // Write output buffer to file
        fwrite(outputBuffer, sizeof(short), BUFFER_SIZE, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}