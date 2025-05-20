//FormAI DATASET v1.0 Category: Audio processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int16_t left;
    int16_t right;
} Sample;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s input_file.raw output_file.raw\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file!\n");
        return 1;
    }

    int32_t num_samples = 0;

    // Find the number of samples in the input file
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    num_samples = file_size / sizeof(Sample);

    // Allocate memory for the samples
    Sample *samples = malloc(sizeof(Sample) * num_samples);

    // Read the samples from the input file
    int32_t i = 0;
    while (fread(&samples[i], sizeof(Sample), 1, input_file) == 1) {
        i++;
    }

    // Apply a simple normalization to each sample
    for (i = 0; i < num_samples; i++) {
        samples[i].left /= 2;
        samples[i].right /= 2;
    }

    // Write the modified samples to the output file
    for (i = 0; i < num_samples; i++) {
        fwrite(&samples[i], sizeof(Sample), 1, output_file);
    }

    // Clean up and exit
    free(samples);
    fclose(input_file);
    fclose(output_file);

    printf("Done!\n");

    return 0;
}