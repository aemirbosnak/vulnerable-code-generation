//FormAI DATASET v1.0 Category: Audio processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *inputFile;
    FILE *outputFile;
    short int inputBuffer[10000];
    short int outputBuffer[10000];
    unsigned long counter = 0;
    double output;
    double sampleRate = 44100.0; // Sample rate in Hz
    double frequency = 440.0; // Frequency to generate in Hz
    double maxAmplitude = 32767; // Maximum amplitude of the output signal
    double samplePeriod = 1.0 / sampleRate;
    double phaseIncrement = 2 * M_PI * frequency * samplePeriod;
    double currentPhase = 0.0;
    int bufferLength;

    inputFile = fopen("audio.wav", "rb"); // Input audio file
    outputFile = fopen("output.wav", "wb"); // Output audio file
    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

    fseek(inputFile, 44, SEEK_SET); // Skip header of the input audio file
    while ((bufferLength = fread(inputBuffer, sizeof(short int), 10000, inputFile)) > 0) { // Read audio data in blocks of 10000 samples
        
        for (int i = 0; i < bufferLength; i++) {
            currentPhase += phaseIncrement;
            if (currentPhase >= 2 * M_PI) {
                currentPhase -= 2 * M_PI;
            }
            output = sin(currentPhase) * maxAmplitude;
            outputBuffer[i] = (short int) output;
        }
        
        fwrite(outputBuffer, sizeof(short int), bufferLength, outputFile);

        counter += bufferLength;
    }
    
    printf("Processed %lu samples.\n", counter);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}