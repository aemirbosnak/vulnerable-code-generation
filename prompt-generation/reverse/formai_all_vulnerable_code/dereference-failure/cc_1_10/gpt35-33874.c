//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

void encrypt(char *input_file, char *output_file, char *key, int key_index, int block_index) {
    // Open input and output files
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");

    // Check if files were opened successfully
    if (input_fp == NULL || output_fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    // Check if we've reached the end of the file
    if (feof(input_fp)) {
        return;
    }

    // Read in a block of data from the input file
    char block[BLOCK_SIZE];
    int num_bytes_read = fread(block, 1, BLOCK_SIZE, input_fp);

    // XOR the block with the current key byte
    for (int i = 0; i < num_bytes_read; i++) {
        block[i] ^= key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }

    // Write the modified block to the output file
    fwrite(block, 1, num_bytes_read, output_fp);

    // Recursively call encrypt on the next block of data
    encrypt(input_file, output_file, key, key_index, block_index + 1);

    // Close the input and output files
    fclose(input_fp);
    fclose(output_fp);
}

void decrypt(char *input_file, char *output_file, char *key, int key_index, int block_index) {
    // Open input and output files
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");

    // Check if files were opened successfully
    if (input_fp == NULL || output_fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    // Check if we've reached the end of the file
    if (feof(input_fp)) {
        return;
    }

    // Read in a block of data from the input file
    char block[BLOCK_SIZE];
    int num_bytes_read = fread(block, 1, BLOCK_SIZE, input_fp);

    // XOR the block with the current key byte
    for (int i = 0; i < num_bytes_read; i++) {
        block[i] ^= key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }

    // Write the modified block to the output file
    fwrite(block, 1, num_bytes_read, output_fp);

    // Recursively call decrypt on the next block of data
    decrypt(input_file, output_file, key, key_index, block_index + 1);

    // Close the input and output files
    fclose(input_fp);
    fclose(output_fp);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key = argv[3];

    // Encrypt the file
    encrypt(input_file, output_file, key, 0, 0);

    // Decrypt the file
    decrypt(output_file, "decrypted.txt", key, 0, 0);

    return 0;
}