//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    FILE *input_file;
    FILE *output_file;
    short int input_buffer[BUFFER_SIZE];
    short int output_buffer[BUFFER_SIZE];
    int i;

    // Open input and output files
    input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read header information from input file
    fseek(input_file, 0, SEEK_SET);
    fread(&i, sizeof(int), 1, input_file); // Chunk ID
    fread(&i, sizeof(int), 1, input_file); // Chunk size
    fread(&i, sizeof(int), 1, input_file); // Format
    fseek(input_file, 0x2c, SEEK_SET);
    fread(&i, sizeof(int), 1, input_file); // Sample rate
    fread(&i, sizeof(int), 1, input_file); // Byte rate
    fread(&i, sizeof(int), 1, input_file); // Block align
    fread(&i, sizeof(int), 1, input_file); // Bits per sample
    printf("Input file format: %d-bit, %d Hz\n", i, i);

    // Initialize buffers
    for (i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = 0;
        output_buffer[i] = 0;
    }

    // Process audio
    while (fread(input_buffer, sizeof(short int), BUFFER_SIZE, input_file) == BUFFER_SIZE) {
        // Apply gain
        for (i = 0; i < BUFFER_SIZE; i++) {
            output_buffer[i] = input_buffer[i] * 2;
        }

        // Write to output file
        fwrite(output_buffer, sizeof(short int), BUFFER_SIZE, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}