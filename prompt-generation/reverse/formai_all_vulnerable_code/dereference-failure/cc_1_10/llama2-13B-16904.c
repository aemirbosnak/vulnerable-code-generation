//LLAMA2-13B DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 4096

int main(void)
{
    // Declare variables
    int i, j, k, n;
    short *buffer;
    double sum, mean, stddev;

    // Initialize buffers
    buffer = (short *)calloc(BUFFER_SIZE, sizeof(short));
    if (!buffer) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    // Read audio file
    FILE *file = fopen("audio.wav", "rb");
    if (!file) {
        perror("Failed to open audio file");
        exit(EXIT_FAILURE);
    }

    // Calculate mean and standard deviation
    sum = 0;
    mean = 0;
    stddev = 0;
    for (i = 0; i < BUFFER_SIZE; i++) {
        short sample = (short)fgetc(file);
        sum += sample;
        mean += sample / BUFFER_SIZE;
        stddev += (sample - mean) * (sample - mean);
    }

    // Normalize audio data
    for (i = 0; i < BUFFER_SIZE; i++) {
        short sample = (short)fgetc(file);
        short normalized = (short)((sample - mean) / stddev * 32767);
        buffer[i] = normalized;
    }

    // Write normalized audio data to file
    FILE *outfile = fopen("output.wav", "wb");
    if (!outfile) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        fputc(buffer[i], outfile);
    }

    fclose(outfile);
    fclose(file);

    free(buffer);

    return 0;
}