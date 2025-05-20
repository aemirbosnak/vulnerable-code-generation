//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {

    // Check if user has provided filename and output filename
    if (argc != 3) {
        printf("Usage: ./data_recovery <filename> <output_filename>\n");
        return 1;
    }

    // Open input file in read mode
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Could not open input file '%s'\n", argv[1]);
        return 1;
    }

    // Create output file in write mode
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Could not create output file '%s'\n", argv[2]);
        return 1;
    }

    // Initialize buffer
    unsigned char block[BLOCK_SIZE];
    int block_number = 0;

    // Read each block from input file and write non-zero blocks to output file
    while (fread(block, sizeof(unsigned char), BLOCK_SIZE, input_file) == BLOCK_SIZE) {
        if (memcmp(block, "\0\0\0\0\0\0\0\0", 8) != 0) {
            fwrite(block, sizeof(unsigned char), BLOCK_SIZE, output_file);
        }
        block_number++;
    }

    // Handle the last block
    int last_block_size = sizeof(unsigned char) * (feof(input_file) ? BLOCK_SIZE : (ftell(input_file) - 1) % BLOCK_SIZE);
    if (last_block_size > 0) {
        fread(block, sizeof(unsigned char), last_block_size, input_file);
        if (memcmp(block, "\0\0\0\0\0\0\0\0", 8) != 0) {
            fwrite(block, sizeof(unsigned char), last_block_size, output_file);
        }
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Data recovery complete!\n");
    return 0;
}