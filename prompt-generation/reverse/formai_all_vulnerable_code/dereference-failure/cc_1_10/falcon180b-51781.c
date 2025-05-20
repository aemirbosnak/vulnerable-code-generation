//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    FILE *input_file, *output_file;
    short int buffer[BUFFER_SIZE];
    float filter_coefficients[4] = {0.5, 0.5, 0.5, 0.5};
    int i, j, k;

    // Open input and output files
    input_file = fopen("input_file.wav", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output_file.wav", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read header from input file
    fseek(input_file, 0, SEEK_SET);
    fread(&buffer, sizeof(short int), 44, input_file);

    // Apply filter to input signal
    for (i = 44; i < SAMPLE_RATE / 4; i++) {
        for (j = 0; j < 4; j++) {
            buffer[i] += filter_coefficients[j] * buffer[i - 44 - j];
        }
    }

    // Write header to output file
    fwrite(&buffer, sizeof(short int), 44, output_file);

    // Apply filter to remaining samples
    for (i = 44; i < SAMPLE_RATE; i++) {
        for (j = 0; j < 4; j++) {
            buffer[i] += filter_coefficients[j] * buffer[i - 44 - j];
        }
        fwrite(&buffer[i], sizeof(short int), 1, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Filtering completed successfully.\n");
    return 0;
}