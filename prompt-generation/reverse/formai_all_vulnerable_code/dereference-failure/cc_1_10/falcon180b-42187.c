//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    FILE *input_file, *output_file;
    short int input_buffer[BUFFER_SIZE];
    short int output_buffer[BUFFER_SIZE];
    int i, j;

    // Open input and output files
    input_file = fopen("input.raw", "rb");
    output_file = fopen("output.raw", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s).\n");
        exit(1);
    }

    // Read input file header
    fseek(input_file, 0L, SEEK_SET);
    fread(&i, sizeof(short int), 1, input_file);
    printf("Input file sample rate: %d Hz\n", i);

    // Initialize input and output buffers
    for (i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = 0;
        output_buffer[i] = 0;
    }

    // Process audio
    while (fread(input_buffer, sizeof(short int), BUFFER_SIZE, input_file) == BUFFER_SIZE) {

        // Apply low-pass filter
        for (i = 0; i < BUFFER_SIZE; i++) {
            output_buffer[i] = (input_buffer[i] + input_buffer[i-1] + input_buffer[i-2]) / 3;
        }

        // Write output file
        fwrite(output_buffer, sizeof(short int), BUFFER_SIZE, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");

    return 0;
}