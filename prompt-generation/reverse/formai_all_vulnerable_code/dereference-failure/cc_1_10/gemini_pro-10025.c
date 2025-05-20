//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int16_t sample_t;

void print_samples(sample_t *samples, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%d ", samples[i]);
    }
    printf("\n");
}

void shift_samples(sample_t *samples, size_t n, int shift)
{
    for (size_t i = 0; i < n; i++) {
        samples[i] <<= shift;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("fopen(input_file)");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("fopen(output_file)");
        return EXIT_FAILURE;
    }

    // Read the number of samples from the input file.
    size_t n_samples;
    fread(&n_samples, sizeof(size_t), 1, input_file);

    // Read the samples from the input file.
    sample_t *samples = malloc(n_samples * sizeof(sample_t));
    if (samples == NULL) {
        perror("malloc(samples)");
        return EXIT_FAILURE;
    }
    fread(samples, sizeof(sample_t), n_samples, input_file);

    // Shift the samples by the specified amount.
    int shift = atoi(argv[3]);
    shift_samples(samples, n_samples, shift);

    // Write the samples to the output file.
    fwrite(&n_samples, sizeof(size_t), 1, output_file);
    fwrite(samples, sizeof(sample_t), n_samples, output_file);

    // Free the allocated memory.
    free(samples);

    // Close the files.
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}