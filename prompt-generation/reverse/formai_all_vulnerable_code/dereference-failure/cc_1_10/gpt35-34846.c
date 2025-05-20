//FormAI DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(double frequency, double duration, char* filename) {
    int sampleRate = 44100; // Sample rate of the wave
    int numSamples = (int)(duration * sampleRate);
    double* buffer = (double*)malloc(numSamples * sizeof(double)); // Allocate memory for the buffer
    
    // Generate the sine wave
    for(int i=0; i<numSamples; i++) {
        buffer[i] = sin(2 * PI * frequency * ((double)i / sampleRate));
    }
    
    // Write the buffer to a file
    FILE* file = fopen(filename, "wb");
    fwrite(buffer, sizeof(double), numSamples, file);
    fclose(file);
    
    free(buffer); // Free the memory
}

// Function to add distortion effect to an audio file
void addDistortion(char* inputFile, char* outputFile, double gain, double threshold) {
    int sampleRate = 44100; // Sample rate of the audio file
    double* inputBuffer = (double*)malloc(sampleRate * sizeof(double)); // Allocate memory for the input buffer
    double* outputBuffer = (double*)malloc(sampleRate * sizeof(double)); // Allocate memory for the output buffer
    
    // Open the input file
    FILE* inputFilePointer = fopen(inputFile, "rb");
    if(inputFilePointer == NULL) {
        printf("Error: Cannot open input file!\n");
        return;
    }
    
    // Open the output file
    FILE* outputFilePointer = fopen(outputFile, "wb");
    if(outputFilePointer == NULL) {
        printf("Error: Cannot open output file!\n");
        return;
    }
    
    // Process the audio samples
    int samplesRead = 0;
    while((samplesRead = fread(inputBuffer, sizeof(double), sampleRate, inputFilePointer)) > 0) {
        for(int i=0; i<samplesRead; i++) {
            double inputSample = inputBuffer[i];
            double outputSample;
            
            // Distortion effect
            if(fabs(inputSample) > threshold) {
                outputSample = ((2.0/3.0) * threshold * gain) * (1 - exp(-(fabs(inputSample) - threshold) * 3 / threshold)) / fabs(inputSample);
            } else {
                outputSample = inputSample * gain;
            }
            
            outputBuffer[i] = outputSample;
        }
        
        fwrite(outputBuffer, sizeof(double), samplesRead, outputFilePointer); // Write the output samples to the output file
    }
    
    // Close the input and output files
    fclose(inputFilePointer); 
    fclose(outputFilePointer);
    
    free(inputBuffer); // Free the memory
    free(outputBuffer);
}

int main() {
    // Generate a sine wave and write it to a file
    double frequency = 440; // A4 note frequency
    double duration = 5; // 5 seconds duration
    char* filename = "sine_wave.bin";
    generateSineWave(frequency, duration, filename);
    
    // Add distortion effect to the sine wave file
    char* inputFile = "sine_wave.bin";
    char* outputFile = "sine_wave_distorted.bin";
    double gain = 2; // 2x gain
    double threshold = 0.3; // Threshold for the distortion effect
    addDistortion(inputFile, outputFile, gain, threshold);
    
    return 0;
}