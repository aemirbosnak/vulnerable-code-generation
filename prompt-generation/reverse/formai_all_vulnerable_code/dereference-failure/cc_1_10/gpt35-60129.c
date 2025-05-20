//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000
#define MAX_OUTPUT_SIZE 500000

// Data structures to store compressed data
static uint8_t compressed_data[MAX_OUTPUT_SIZE];
static uint8_t compressed_data_curr_pos = 0;

// Bit manipulation macros
#define bit_set(value, bit) ((value) |= (1UL << (bit))) // Set a bit to 1
#define bit_clear(value, bit) ((value) &= ~(1UL << (bit))) // Clear a bit to 0
#define bit_get(value, bit) (((value) >> (bit)) & 1) // Get the value of a bit

// Compress the input data
static void compress_data(const uint8_t *input_data, const int input_size) {
    uint8_t bit = 0; // Current bit being written
    uint8_t byte = 0; // Current byte being written
    for (int i = 0; i < input_size; ++i) {
        const uint8_t input_byte = input_data[i];
        for (int j = 0; j < 8; ++j) {
            if (bit_get(input_byte, j)) { // Check if the bit is set
                bit_set(byte, bit); // Set the corresponding bit in the byte
            }
            if (++bit == 8) { // Check if the byte is full
                compressed_data[compressed_data_curr_pos++] = byte; // Write the byte to output stream
                byte = 0; // Reset the byte
                bit = 0; // Reset the bit
                if (compressed_data_curr_pos == MAX_OUTPUT_SIZE) { // Check if output buffer is full
                    return;
                }
            }
        }
    }
    if (bit > 0) { // Check if the last byte is not full
        compressed_data[compressed_data_curr_pos++] = byte; // Write the last byte to output stream
    }
}

// Decompress the input data
static void decompress_data(const uint8_t *input_data, const int input_size, uint8_t *output_data) {
    uint8_t bit = 0; // Current bit being read
    uint8_t byte = 0; // Current byte being read
    int output_size = 0; // Length of the decompressed data
    for (int i = 0; i < input_size; ++i) {
        const uint8_t input_byte = input_data[i];
        for (int j = 0; j < 8; ++j) {
            if (bit_get(input_byte, j)) { // Check if the bit is set
                bit_set(byte, bit); // Set the corresponding bit in the byte
            }
            if (++bit == 8) { // Check if the byte is full
                output_data[output_size++] = byte; // Write the byte to output stream
                byte = 0; // Reset the byte
                bit = 0; // Reset the bit
                if (output_size == MAX_INPUT_SIZE) { // Check if output buffer is full
                    return;
                }
            }
        }
    }
    if (bit > 0) { // Check if the last byte is not full
        output_data[output_size++] = byte; // Write the last byte to output stream
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) { // Check if the number of arguments is correct
        printf("Usage: %s <mode> <input file>\n", argv[0]);
        exit(1);
    }

    const char *mode = argv[1];
    const char *input_file = argv[2];

    if (strcmp(mode, "compress") != 0 && strcmp(mode, "decompress") != 0) { // Check if the mode is valid
        printf("Invalid mode: %s\n", mode);
        exit(1);
    }

    FILE *fp = fopen(input_file, "rb"); // Open the input file
    if (fp == NULL) {
        printf("Failed to open input file: %s\n", input_file);
        exit(1);
    }

    // Read the input data
    uint8_t input_data[MAX_INPUT_SIZE];
    const int input_size = fread(input_data, 1, MAX_INPUT_SIZE, fp);

    fclose(fp); // Close the input file

    if (strcmp(mode, "compress") == 0) { // Compress the input data
        compress_data(input_data, input_size);

        FILE *fp_out = fopen("output.bin", "wb"); // Open the output file
        if (fp_out == NULL) {
            printf("Failed to open output file: output.bin\n");
            exit(1);
        }

        // Write the compressed data to output file
        fwrite(compressed_data, 1, compressed_data_curr_pos, fp_out);
        fclose(fp_out); // Close the output file

    } else { // Decompress the input data
        uint8_t output_data[MAX_INPUT_SIZE];

        decompress_data(input_data, input_size, output_data);

        FILE *fp_out = fopen("output.bin", "wb"); // Open the output file
        if (fp_out == NULL) {
            printf("Failed to open output file: output.bin\n");
            exit(1);
        }

        // Write the decompressed data to output file
        fwrite(output_data, 1, input_size, fp_out);
        fclose(fp_out); // Close the output file
    }

    printf("Done!\n");

    return 0;
}