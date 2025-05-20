//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    FILE *input_file, *output_file;
    short int buffer[BUFFER_SIZE];
    int bytes_read;
    float frequency, amplitude, phase;

    // Open input file
    input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read header information from input file
    fseek(input_file, 44, SEEK_SET); // Skip 44 bytes of header information
    fread(&bytes_read, sizeof(int), 1, input_file);
    fread(buffer, sizeof(short int), BUFFER_SIZE, input_file);

    // Generate sine wave with specified frequency and amplitude
    frequency = 440; // Hz
    amplitude = 0.5; // Between 0 and 1
    phase = 0; // radians

    // Fill buffer with sine wave
    for (int i = 0; i < BUFFER_SIZE; i++) {
        float sample = amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE + phase);
        buffer[i] = (short int) (sample * 32767);
    }

    // Write buffer to output file
    fwrite(buffer, sizeof(short int), BUFFER_SIZE, output_file);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}