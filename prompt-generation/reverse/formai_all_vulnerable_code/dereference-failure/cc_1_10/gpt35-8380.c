//FormAI DATASET v1.0 Category: Audio processing ; Style: Claude Shannon
/*
 * This audio processing program implemented in C takes in a .wav file, applies a low-pass filter
 * to isolate the lower frequencies, increases the volume of the audio, and outputs the processed audio to a new .wav file.
 * The audio samples are represented as 16-bit signed integers, and the program follows the Nyquist-Shannon sampling theorem
 * to ensure that our filter does not result in aliasing. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./audioProcess [input.wav] [output.wav]\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read the header of the input .wav file
    char riffChunkID[4], waveType[4], fmtChunkID[4], dataChunkID[4];
    uint32_t riffChunkSize, fmtChunkSize, audioFormat, numChannels, sampleRate, byteRate, blockAlign, bitsPerSample, dataChunkSize;

    fread(riffChunkID, sizeof(char), 4, inputFile);
    fread(&riffChunkSize, sizeof(uint32_t), 1, inputFile);
    fread(waveType, sizeof(char), 4, inputFile);
    fread(fmtChunkID, sizeof(char), 4, inputFile);
    fread(&fmtChunkSize, sizeof(uint32_t), 1, inputFile);
    fread(&audioFormat, sizeof(uint16_t), 1, inputFile);
    fread(&numChannels, sizeof(uint16_t), 1, inputFile);
    fread(&sampleRate, sizeof(uint32_t), 1, inputFile);
    fread(&byteRate, sizeof(uint32_t), 1, inputFile);
    fread(&blockAlign, sizeof(uint16_t), 1, inputFile);
    fread(&bitsPerSample, sizeof(uint16_t), 1, inputFile);
    fread(dataChunkID, sizeof(char), 4, inputFile);
    fread(&dataChunkSize, sizeof(uint32_t), 1, inputFile);

    // Write the header of the output .wav file
    fwrite(riffChunkID, sizeof(char), 4, outputFile);
    fwrite(&riffChunkSize, sizeof(uint32_t), 1, outputFile);
    fwrite(waveType, sizeof(char), 4, outputFile);
    fwrite(fmtChunkID, sizeof(char), 4, outputFile);
    fwrite(&fmtChunkSize, sizeof(uint32_t), 1, outputFile);
    fwrite(&audioFormat, sizeof(uint16_t), 1, outputFile);
    fwrite(&numChannels, sizeof(uint16_t), 1, outputFile);
    fwrite(&sampleRate, sizeof(uint32_t), 1, outputFile);
    fwrite(&byteRate, sizeof(uint32_t), 1, outputFile);
    fwrite(&blockAlign, sizeof(uint16_t), 1, outputFile);
    fwrite(&bitsPerSample, sizeof(uint16_t), 1, outputFile);
    fwrite(dataChunkID, sizeof(char), 4, outputFile);
    fwrite(&dataChunkSize, sizeof(uint32_t), 1, outputFile);

    // Pre-compute variables for low-pass filter
    double fc = 1000.0; // 1 kHz cutoff frequency
    double wc = 2.0 * PI * fc / sampleRate;
    double alpha = sin(wc) / (2.0 * 0.707); // 0.707 is the quality factor
    double a0 = 1.0 + alpha;
    double a1 = -2.0 * cos(wc) / a0;
    double a2 = (1.0 - alpha) / a0;
    double b0 = (1.0 - cos(wc)) / (2.0 * a0); // only need b0 because it's a first-order filter
    double yn = 0.0, xn[2], ynminus1 = 0.0, xnminus1[2];

    // Process audio samples
    int16_t sample;
    while (fread(&sample, sizeof(int16_t), 1, inputFile)) {
        xn[0] = (double) sample / 32767.0; // normalize to [-1, 1] range
        xn[1] = xnminus1[0];
        yn = b0*xn[0] + b0*xn[1] - a1*ynminus1 - a2*yn;

        sample = (int16_t) round(yn * 32767.0); // denormalize and scale back to 16-bit range
        sample *= 2; // double the volume

        fwrite(&sample, sizeof(int16_t), 1, outputFile);

        xnminus1[0] = xn[0];
        xnminus1[1] = xn[1];
        ynminus1 = yn;
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}