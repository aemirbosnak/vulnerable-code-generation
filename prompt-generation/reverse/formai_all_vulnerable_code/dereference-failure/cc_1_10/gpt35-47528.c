//FormAI DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

typedef struct compression_header {
    char magic[8];
    int original_size;
    int compressed_size;
} compression_header_t;

void encrypt(char *buffer, size_t size) {
    for (int i = 0; i < size; i++) {
        buffer[i] ^= 0xFF;
    }
}

void compress(char *input_file_path, char *output_file_path) {
    FILE *input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_file_path, "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    char input_buffer[MAX_SIZE];
    size_t bytes_read, compressed_size = 0;

    while ((bytes_read = fread(input_buffer, 1, MAX_SIZE, input_file)) > 0) {
        // Compress the input buffer here using your favourite algorithm
        // and write it to the output file

        encrypt(input_buffer, bytes_read);
        compressed_size += bytes_read;

        fwrite(input_buffer, 1, bytes_read, output_file);
    }

    compression_header_t header = {"PARACOMP", ftell(input_file), compressed_size};
    fwrite(&header, sizeof(compression_header_t), 1, output_file);

    fclose(input_file);
    fclose(output_file);
}

void decompress(char *input_file_path, char *output_file_path) {
    FILE *input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    compression_header_t header;
    fread(&header, sizeof(compression_header_t), 1, input_file);

    FILE *output_file = fopen(output_file_path, "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    char input_buffer[MAX_SIZE];
    size_t bytes_read, decompressed_size = 0;

    while ((bytes_read = fread(input_buffer, 1, MAX_SIZE, input_file)) > 0) {
        // Decompress the input buffer here using your favourite algorithm

        encrypt(input_buffer, bytes_read);

        fwrite(input_buffer, 1, bytes_read, output_file);
        decompressed_size += bytes_read;
    }

    if (decompressed_size != header.original_size) {
        fprintf(stderr, "Decompressed size does not match original size\n");
        exit(EXIT_FAILURE);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s (compress|decompress) <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
    } else {
        printf("Invalid operation\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}