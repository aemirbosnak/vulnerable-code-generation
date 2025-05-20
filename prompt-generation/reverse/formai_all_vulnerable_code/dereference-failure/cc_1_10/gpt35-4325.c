//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1000

typedef struct {
    int count;
    char character;
} Run;

void compress(char *input, int input_size, char *output, int *output_size) {
    int i = 0, j = 0;
    Run current_run = {0, '\0'};
    bool new_run = true;

    while (i < input_size) {
        // Check if current character is equal to last one
        if (input[i] == current_run.character) {
            current_run.count++;
        } else {
            // Store current run
            if (!new_run) {
                output[j] = current_run.character;
                *(int *)(output+j+1) = current_run.count;
                j += sizeof(Run);
                current_run = (Run){0, '\0'};
            }

            // Start new run
            current_run.character = input[i];
            current_run.count = 1;
            new_run = false;
        }

        i++;

        // Check for buffer overflow
        if (j + sizeof(Run) >= *output_size) {
            printf("Error: Output buffer overflow\n");
            exit(1);
        }
    }

    // Store final run
    output[j] = current_run.character;
    *(int *)(output+j+1) = current_run.count;
    j += sizeof(Run);

    *output_size = j;
}

void decompress(char *input, int input_size, char *output, int *output_size) {
    int i = 0, j = 0;

    while (i < input_size) {
        Run current_run = *(Run *)(input+i);
        i += sizeof(Run);

        for (int k = 0; k < current_run.count; k++) {
            output[j++] = current_run.character;
        }

        // Check for buffer overflow
        if (j >= *output_size) {
            printf("Error: Output buffer overflow\n");
            exit(1);
        }
    }

    *output_size = j;
}

int main() {
    // Read input from file
    char *input = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));
    FILE *infile = fopen("input.txt", "r");
    int input_size = fread(input, sizeof(char), MAX_INPUT_SIZE, infile);
    fclose(infile);

    // Compress input
    char *compressed = (char *)malloc(2 * MAX_INPUT_SIZE * sizeof(char));
    int compressed_size = 2 * MAX_INPUT_SIZE;
    compress(input, input_size, compressed, &compressed_size);

    // Write compressed output to file
    FILE *outfile = fopen("compressed.bin", "wb");
    fwrite(compressed, sizeof(char), compressed_size, outfile);
    fclose(outfile);

    // Read compressed input from file
    char *compressed_input = (char *)malloc(compressed_size * sizeof(char));
    FILE *compressed_file = fopen("compressed.bin", "rb");
    fread(compressed_input, sizeof(char), compressed_size, compressed_file);
    fclose(compressed_file);

    // Decompress input
    char *decompressed = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));
    int decompressed_size = MAX_INPUT_SIZE;
    decompress(compressed_input, compressed_size, decompressed, &decompressed_size);

    // Write decompressed output to file
    FILE *decompressed_file = fopen("output.txt", "w");
    fwrite(decompressed, sizeof(char), decompressed_size, decompressed_file);
    fclose(decompressed_file);

    // Free memory
    free(input);
    free(compressed);
    free(compressed_input);
    free(decompressed);

    return 0;
}