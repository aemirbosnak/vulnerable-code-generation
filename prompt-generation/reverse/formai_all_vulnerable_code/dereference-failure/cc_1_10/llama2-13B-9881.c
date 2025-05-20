//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024*1024
#define MAX_OUTPUT_SIZE 512

// Structure to hold the compression statistics
typedef struct {
    int num_bytes;
    int num_occurrences[256];
} compression_stats;

// Function to calculate the compression statistics
void calculate_stats(const char* input_file, size_t input_size, compression_stats* stats) {
    FILE* file = fopen(input_file, "r");
    char buffer[4096];
    size_t bytes_read = fread(buffer, 1, 4096, file);
    while (bytes_read > 0) {
        for (int i = 0; i < 256; i++) {
            stats->num_occurrences[i] += (buffer[i] == buffer[i]);
        }
        bytes_read = fread(buffer, 1, 4096, file);
    }
    fclose(file);
}

// Function to compress the input data
void compress(const char* input_file, size_t input_size, compression_stats* stats, char* output_file) {
    // Step 1: Calculate the compression statistics
    calculate_stats(input_file, input_size, stats);

    // Step 2: Build the compression dictionary
    char* dictionary = malloc(stats->num_occurrences[0] * 2);
    int* frequencies = malloc(stats->num_occurrences[0] * 2);
    int i = 0;
    for (int j = 0; j < 256; j++) {
        if (stats->num_occurrences[j] > 0) {
            dictionary[i] = j;
            frequencies[i] = stats->num_occurrences[j];
            i++;
        }
    }

    // Step 3: Compress the input data
    char* current = output_file;
    for (size_t i = 0; i < input_size; i++) {
        char c = input_file[i];
        if (c == dictionary[*current]) {
            // Found a match!
            *current++ = frequencies[*current];
        } else {
            // Not found, write the character as-is
            *current++ = c;
        }
    }

    // Step 4: Write the compressed data to disk
    size_t compressed_size = current - output_file;
    printf("Compressed %zu bytes to %zu bytes (%zu%%)\n", input_size, compressed_size, (compressed_size * 100) / input_size);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <input_size> <output_file>\n", argv[0]);
        return 1;
    }

    // Step 1: Read the input file
    size_t input_size = atoi(argv[2]);
    char* input_file = malloc(input_size);
    FILE* file = fopen(argv[1], "r");
    fread(input_file, 1, input_size, file);
    fclose(file);

    // Step 2: Calculate the compression statistics
    compression_stats stats;
    calculate_stats(input_file, input_size, &stats);

    // Step 3: Compress the input data
    char* output_file = malloc(stats.num_occurrences[0] * 2);
    compress(input_file, input_size, &stats, output_file);

    // Step 4: Write the compressed data to disk
    FILE* outfile = fopen(argv[3], "w");
    fwrite(output_file, 1, stats.num_occurrences[0] * 2, outfile);
    fclose(outfile);

    free(input_file);
    free(output_file);
    return 0;
}