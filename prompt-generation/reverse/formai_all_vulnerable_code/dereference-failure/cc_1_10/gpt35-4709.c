//FormAI DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *in_file, *out_file; // input and output files
    int16_t buffer[BUFFER_SIZE]; // audio buffer
    uint32_t samples_read, samples_written; // number of samples read and written
    int8_t volume = 20; // amplification factor, range [-127, 127]

    // open input file
    in_file = fopen("in.wav", "rb");
    if (!in_file) {
        perror("Error opening input file");
        return 1;
    }

    // open output file
    out_file = fopen("out.wav", "wb");
    if (!out_file) {
        perror("Error opening output file");
        return 1;
    }

    // read input file header
    char header[44];
    fread(header, 1, 44, in_file);

    // write header to output file
    fwrite(header, 1, 44, out_file);

    // process input file
    while ((samples_read = fread(buffer, sizeof(int16_t), BUFFER_SIZE, in_file))) {
        // amplify audio
        for (uint32_t i = 0; i < samples_read; i++) {
            if (buffer[i] > (INT16_MAX - volume)) buffer[i] = INT16_MAX;
            else if (buffer[i] < (INT16_MIN + volume)) buffer[i] = INT16_MIN;
            else buffer[i] += volume;
        }

        // write amplified audio to output file
        samples_written = fwrite(buffer, sizeof(int16_t), samples_read, out_file);
        if (samples_written != samples_read) {
            perror("Error writing audio to output file");
            return 1;
        }
    }

    // close files
    fclose(in_file);
    fclose(out_file);

    printf("Audio processing complete!\n");

    return 0;
}