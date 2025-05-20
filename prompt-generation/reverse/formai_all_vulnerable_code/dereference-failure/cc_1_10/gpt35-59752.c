//FormAI DATASET v1.0 Category: Audio processing ; Style: introspective
/*
 * This program demonstrates an audio processing example in C language.
 * It takes an input audio file and applies a low-pass filter on it to remove high-frequency noise.
 * The processed file is then written to an output file.
 *
 * Author: Your Name
 * Date: Today's Date
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BUFFER_SIZE 1024   // buffer size for reading/writing audio data
#define SAMPLE_RATE 44100  // audio sample rate (Hz)
#define CUTOFF_FREQ 5000   // low-pass filter cutoff frequency (Hz)

/* Function to apply a low-pass filter on audio data */
void lowPassFilter(int16_t* buffer, int size) {
    double RC = 1.0 / (2.0 * M_PI * CUTOFF_FREQ);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    double y_prev = 0.0;

    for (int i = 0; i < size; i++) {
        double y = buffer[i] * alpha + y_prev * (1.0 - alpha);
        buffer[i] = (int16_t) round(y);
        y_prev = y;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_audio_file> <output_audio_file>\n", argv[0]);
        exit(1);
    }

    char* inFilename = argv[1];
    char* outFilename = argv[2];

    FILE* inFile = fopen(inFilename, "rb");
    if (inFile == NULL) {
        fprintf(stderr, "Error: Unable to open input audio file '%s'\n", inFilename);
        exit(1);
    }

    FILE* outFile = fopen(outFilename, "wb");
    if (outFile == NULL) {
        fprintf(stderr, "Error: Unable to open output audio file '%s'\n", outFilename);
        exit(1);
    }

    int16_t buffer[BUFFER_SIZE];

    while (!feof(inFile)) {
        int bytesRead = fread(buffer, sizeof(int16_t), BUFFER_SIZE, inFile);
        lowPassFilter(buffer, bytesRead);
        fwrite(buffer, sizeof(int16_t), bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);

    printf("Audio processing completed successfully!\n");

    return 0;
}